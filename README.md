# BASED Utility

## sdisk - The BASED, Suckless, Simple Disk Space Checker

The `BASED` sdisk (The BASED, Suckless, Simple Disk Space Checker) is a tool that allows you to check the free space left on the Linux machine with the system libraries provided by Rust.

### Features

- **Universal Compatibility**: The `BASED` sdisk can be built on any Linux distribution, making it compatible with any distribution based on the Linux kernel.
- **Source Code Distribution**: The `BASED` sdisk is distributed as source code rather than a pre-built binary, promoting transparency and flexibility.
- **Memory Safety**: The `BASED` sdisk uses the `free()` function to deallocate memory once it's no longer needed, helping prevent memory leaks and contributing to the overall safety of the utility.
- **Accuracy**: The `BASED` sdisk utility is accurate when gathering data as it uses the system libraries in C.

### Building from Source

As per the "suckless" philosophy, the `BASED` sdisk is designed to be built from source. Here's how you can do it with the use of the Makefile:

```
# make clean install
```

### Usage

Using the $PATH environment variable you can run it indirectly without typing in the whole path:

```
$ sdisk
```

### Contributing

You may contribute to `sdisk` by building, and making pull requests or opening an issue.

### License

`sdisk` is an open source software licensed under GNU General Public License version 3.0 (GPLv3.0)
