section	.text
	global	_ft_strcmp

_ft_strcmp:
	mov	rax, 0
	mov	rbx, 0
	jmp	compare

compare:
	mov	al, BYTE [rdi]
	mov	bl, BYTE [rsi]
	cmp	al, bl
	je	same
	jne	diff

same:
	cmp	al, 0
	je	end
	inc	rdi
	inc rsi
	jmp	compare

diff:
	sub	rax, rbx
	ret

end:
	mov	rax, 0
	ret
