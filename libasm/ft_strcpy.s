section	.text
	global	_ft_strcpy

_ft_strcpy:
	mov	rax, 0
	cmp	rsi, 0
	je	end

copy:
	mov	cl, BYTE [rsi + rax]
	mov BYTE [rdi + rax], cl
	cmp	cl, 0
	je	end
	inc	rax
	jmp	copy

end:
	mov	rax, rdi
	ret
