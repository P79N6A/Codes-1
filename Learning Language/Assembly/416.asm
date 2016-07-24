;*************************************************************
ds_segment segment at 0E000H  ; 从0E00H开始定义一个既是字又是字节的数组
	ARRAY_B LABEL BYTE
	ARRAY_W DW 50 DUP (?)
ds_segment segment ends
;*************************************************************
ss_segment segment PARA STACK ‘STACK’ ; para表示段起始地址位于可用的第一节（每节16字节），'stack'是类别名
	DW 100H DUP (?)
	TOS LABEL WORD
ss_segment segment ends
;*************************************************************
code segment
;-------------------------------------------------------------
main proc far

assume cs:code, ds:ds_segment, ss: ss_segment

ORG 1000H

start: 
	mov ax, ss_segment
	mov ss, ax
	mov sp, offset TOS
	push ds
	mov ax, 0
	push ax
	mov ax,ds_segment
	mov ds, ax
	ret

main endp

code ends
;*************************************************************
end start