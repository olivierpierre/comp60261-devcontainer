.global _start

.text
_start:
    # write(1, message, 14)
    mov $1, %rax
    mov $1, %rdi
    mov $message, %rsi
    mov $14, %rdx
    syscall

# exit(0)
    mov $60, %rax
    xor %rdi, %rdi
    syscall

message:
    .ascii "Hello, world!\n"
