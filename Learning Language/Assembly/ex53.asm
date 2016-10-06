;*************************************************************
ds_segment segment
	string1 db 50, 0, 50 dup(?)
	string2 db 50, 0, 50 dup(?)
	mess1 db "Please enter the first string:$"
	mess2 db "Please enter the second string:$"
	judge1 db "true$"
	judge2 db "false$"
ds_segment ends
;*************************************************************
ss_segment segment
	
ss_segment ends
;*************************************************************
code segment
;-------------------------------------------------------------
assume cs:code, ds:ds_segment, ss:ss_segment

main:
	mov ax, ds_segment
	mov ds, ax
	mov ax, ss_segment
	mov ss, ax
	
	; 输入第一个字符串
	lea dx, mess1
	mov ah, 9
	int 21h
	
	mov dx, offset string1
	mov ah, 0ah
	int 21h
	call changeline
	
	; 输入第二个字符串
	lea dx, mess2
	mov ah, 9
	int 21h
	
	mov dx, offset string2
	mov ah, 0ah
	int 21h
	call changeline
	
	lea si, string1
	lea di, string2

	
	; 字符串比较
	lp:
		mov bl, byte ptr [di]
		cmp [si], bl
		jnz false
		inc si
		inc di
		cmp byte ptr [si], 0
	jnz lp
	
	; 相等
	lea dx, judge1
	mov ah, 9
	int 21h
	jmp ed
	
	; 不相等
	false:
		lea dx, judge2
		mov ah, 9
		int 21h
		jmp ed
	
	; 回车换行
	changeline proc near
		mov dl, 0dh
		mov ah, 2
		int 21h
		
		mov dl, 0ah
		mov ah, 2
		int 21h
		ret
	changeline endp
ed:
	mov ah, 4ch
	int 21h
code ends
;*************************************************************
end main
	
	