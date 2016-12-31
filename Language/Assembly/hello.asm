datas segment
	string db 'hello world!!!',13,10,'$'
datas ends
codes segment
	assume cs:codes,ds:datas
	
start:
	mov ax,datas
	mov ds,ax
	lea dx,string
	mov ah,9
	int 21h
	mov ah,4ch
	int 21h
codes ends
	end start