#include <stdio.h>
#include <sys/statvfs.h>

// Function to convert disk size in bytes to a human-readable format
void human_readable_size(unsigned long size) {
    const char *units[] = {"B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};
    double size_f64 = (double)size;
    int unit_index = 0;

    // Divide the size by 1024 until it's less than 1024 or we reach the largest unit
    while (size_f64 >= 1024.0 && unit_index < sizeof(units) / sizeof(units[0]) - 1) {
        size_f64 /= 1024.0;
        unit_index++;
    }

    // Format the size with two decimal places and append the unit
    printf("Disk Space: %.2f %s\n", size_f64, units[unit_index]);
}

int main() {
    struct statvfs stat;

    // Call the statvfs system call to retrieve file system statistics for the root directory (/)
    if (statvfs("/", &stat) != 0) {
        fprintf(stderr, "Failed to get disk usage for root directory\n");
        return 1;
    }

    // Extract relevant information from the statvfs struct
    unsigned long block_size = stat.f_bsize;
    unsigned long blocks_available = stat.f_blocks;
    unsigned long blocks_used = stat.f_blocks - stat.f_bfree;

    // Calculate the total disk size and used disk size
    unsigned long total_size = blocks_available * block_size;
    unsigned long used_size = blocks_used * block_size;

    // Calculate the disk usage percentage
    double disk_usage_percentage = ((double)used_size / total_size) * 100.0;

    // Calculate the available disk space by subtracting the used space from the total space
    unsigned long available_size = stat.f_bavail * block_size;

    // Print the available disk space and disk usage percentage
    human_readable_size(available_size);
    printf("Disk Percentage: %.2f%%\n", disk_usage_percentage);

    return 0;
}
