bits 16
org 0x7c00

start:
cli
xor ax,ax
mov ds,ax
mov es,ax
mov ss,ax
mov sp,0x7c00

mov ax,0x0013
int 0x10

mov ax,0xa000
mov es,ax
mov di,(320*80+140)
mov cx,2000

logo:
mov al,0xf0
stosb
loop logo

mov ah,02h
mov al,20
mov ch,0
mov cl,2
mov dh,0
mov bx,0x1000
int 13h

cli
lgdt [gdt_desc]

mov eax,cr0
or eax,1
mov cr0,eax

jmp 08h:pmode

bits 32
pmode:

mov ax,10h
mov ds,ax
mov es,ax
mov ss,ax
mov esp,0x90000

jmp 0x1000

gdt_start:
dq 0
dq 0x00cf9a000000ffff
dq 0x00cf92000000ffff

gdt_desc:
dw gdt_end-gdt_start-1
dd gdt_start
gdt_end:

times 510-($-$$) db 0
dw 0xaa55
