;*************************************************************
dataseg segment
	inbuf db 12 dup(?)
	outname db 16 dup(?)
	outphone db 12 dup(?), 0dh, 0ah, '$'
	message1 db 'INPUT NAME:$'
	message2 db 'INPUT  A  TELEPHONE  NUMBER:$'
	message3 db 'NAME	TEL.', 0dh, 0ah, '$'
	crlf db 0dh, 0ah, '$'
dataseg ends
;*************************************************************
stackseg segment
	dw 100 dup(?)
	tos label word
stackseg ends
;*************************************************************
; 自定义宏，用于输出信息
Output macro message
	mov ah, 09h
	lea dx, message
	int 21h
endm
;*************************************************************
codeseg segment
telist proc far
assume cs:codeseg, ds:dataseg, ss:stackseg, es:dataseg
;-------------------------------------------------------------
start:
	mov ax, stackseg
	mov ss, ax
	mov sp, offset tos
	push ds
	mov  ax, 0
	push ax
	mov ax, dataseg
	mov ds, ax
	mov es, ax
	
	Output message1
	call input_name
	
	Output message2
	call inphone
	
	call printline
	
	ret
	
telist endp

input_name proc near
	call getchar
	lea si, inbuf
	lea di, outname
	mov cx, 12
	cld
	rep movsb   ; 复制名字
	ret
input_name endp

inphone proc near
	call getchar
	lea si, inbuf
	lea di, outphone
	cld
	rep movsb   ; 复制电话号码
	ret
inphone endp

getchar proc near
	mov al, 20h ; '$'
	mov cx, 12
	lea di, inbuf
	cld
	rep stosb   ; 将al的值传到es段的DI地址处，初始化
	mov cx, 12
	mov di, 0
input:
	mov ah, 1
	int 21h
	cmp al, 0dh
	jz quit
	mov inbuf[di], al
	inc di
	loop input
quit:
	Output crlf
	ret
getchar endp

printline proc near
	Output message3
	Output outname
	ret
printline endp

codeseg ends
;*************************************************************
end start