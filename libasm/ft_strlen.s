section .text ;실행할 코드를 작성하는 공간
	global _ft_strlen

_ft_strlen:
	mov rax, 0 ;rax = 0 카운터 변수 초기화
	jmp count

count:
	cmp BYTE [rdi + rax], 0 ;rdi: 매개변수 s
	je	end
	inc	rax
	jmp	count

end:
	ret ;함수 종료. rax 레지스터 반환
