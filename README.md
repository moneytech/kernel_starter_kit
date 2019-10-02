# kernel\_starter\_kit
Boilerplate for creating operating system kernels.
The goal of this repository is to provide the bare minimum
functionality necessary for a simple kernel, compiled as a static library.

Contained are documented C headers and sources for:
* Multiboot2 (see [GNU Grub](https://www.gnu.org/software/grub/))
* Manipulating the [Global Descriptor Table](https://wiki.osdev.org/GDT)
* Manipulating the [Interrupt Descriptor Table](https://wiki.osdev.org/Interrupt_Descriptor_Table)
  * Handling interrupts
* Memory management via [Paging](https://wiki.osdev.org/Paging)
* Context switching, and manipulating the
[Task State Segment](https://wiki.osdev.org/Task_State_Segment)
* Using [newlib](https://sourceware.org/newlib/) to build a Ring 0 `libc`
