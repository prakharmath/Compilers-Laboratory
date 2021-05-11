	.file	"assgn1.c" #name of the file 
	.section	.rodata  #read only data segment will throw an exception if we try to modify this segment
	.align 8   #align directive followed by a power of 2,enforce alignment of the instruction or data immediately after the directive
.LC0:  #Local constant where numbering starts from zero
	.string	"Enter the dimension of a square matrix: "#Input of the size of the square matrix
.LC1:  #Local constant number 1 
	.string	"%d"  #Scanning the size of the square matrix from the user
	.align 8
.LC2:  #Local constant number 2 
	.string	"Enter the first matix (row-major): " #Prompt to enter the first matrix
	.align 8
.LC3:  #Local constant number 3 
	.string	"Enter the second matix (row-major): " #Prompt to enter the second matrix
.LC4:  #Local constant number 4 
	.string	"\nThe result matrix:"   #Prompt to print the final matrix after multiplication
.LC5:  #Local constant number 5 
	.string	"%d "
	.text
	.globl	main  #we define a global function called main which is visible to other functions
	.type	main, @function#global function named main
main:
.LFB0:  #local function beginning(main in this case)
	.cfi_startproc #Included at the beginning of a function which initialises some local data structures
	pushq	%rbp  #Memory locations(rbp and rsp).Create frame pointers here
	.cfi_def_cfa_offset 16  #specifies the change of stack pointer when main is called
	.cfi_offset 6, -16   #specifiying the offset for change in stack pointers
	movq	%rsp, %rbp  #Load the base pointer to the newly created frame pointer
	.cfi_def_cfa_register 6 #CFI Directives, mainly used for debugging purposes
	subq	$4832, %rsp  #Allocate some space (4832 bytes) to the memory stack(Stack frame)
	movq	%fs:40, %rax  #Segment Addressing,Mainly used as stack guard
	movq	%rax, -8(%rbp) #loads rax into the address which is below rbp by 8 bytes
	xorl	%eax, %eax  #clear out %eax
	movl	$.LC0, %edi #first argument for printf
	movl	$0, %eax #second argument for printf
	call	printf  #call printf
	leaq	-4828(%rbp), %rax   
	movq	%rax, %rsi #loads the address of rax to rsi(register store index)
	movl	$.LC1, %edi  #first argument for scanf
	movl	$0, %eax  #second argument for scanf
	call	__isoc99_scanf #call to scanf
	movl	$.LC2, %edi #load the string to be printed next
	movl	$0, %eax  #number of vector registers used
	call	printf  #call to printf
	movl	-4828(%rbp), %eax #accumulator register
	leaq	-4816(%rbp), %rdx
	movq	%rdx, %rsi  #copy the data of %rdx to register store index
	movl	%eax, %edi  #value of n is copied and is sent in the call to the function read matrix
	call	ReadMat #function call to read matrix
	movl	$.LC3, %edi  #Load the string to be printed
	movl	$0, %eax  #number of vector registers used
	call	printf  #another call to printf
	movl	-4828(%rbp), %eax  #n as first argument
	leaq	-3216(%rbp), %rdx  #matrix as second argument(its beginning obviously)
	movq	%rdx, %rsi #pass B's address
	movl	%eax, %edi #pass n as first argument
	call	ReadMat  #another call read matrix
	movl	-4828(%rbp), %eax #push n onto %eax
	leaq	-1616(%rbp), %rcx #address of C ,4th argument
	leaq	-3216(%rbp), %rdx #address of B, 3rd argument
	leaq	-4816(%rbp), %rsi #address of A ,2nd argument
	movl	%eax, %edi  #pass n as first argument
	call	MatMult  #calling the matrix multiplication function
	movl	$.LC4, %edi #Load the string to be printed
	call	puts #Puts is the same as printing a string using printf statement
	movl	$0, -4824(%rbp) #outerloop parameter initialisation
	jmp	.L2  #unconditional jump to loop 2 
.L5:
	movl	$0, -4820(%rbp) #innerloop parameter initialisation
	jmp	.L3  #unconditional jump to loop 3 
.L4:
	movl	-4820(%rbp), %eax #copy inner loop variable to %eax
	movslq	%eax, %rcx#move signed extended double word to %rcx
	movl	-4824(%rbp), %eax #copy outer loop variable to %eax
	movslq	%eax, %rdx#move signed extended double word to %rcx
	movq	%rdx, %rax #load the value of rax onto rdx
	salq	$2, %rax #quadruple the value of rax 
	addq	%rdx, %rax #replace the value of rdx by the sum of rdx and rax 
	salq	$2, %rax #quadruple the value of rax
	addq	%rcx, %rax #replace the value of rcx by the sum of rcx and rax
	movl	-1616(%rbp,%rax,4), %eax #load the value of the first argument onto %eax,4 is the size of ints which is multipled and -1616 is the base address
	movl	%eax, %esi #load the value of eax to esi for the use of printf
	movl	$.LC5, %edi  #load #d as the first argument of printf
	movl	$0, %eax #number of vector registers
	call	printf  #yet another call to printf
	addl	$1, -4820(%rbp) #increment j by 1 
.L3:
	movl	-4828(%rbp), %eax #load the variable n onto eax
	cmpl	%eax, -4820(%rbp) #compare in the loop if j<n
	jl	.L4 #if j<n then again go to L4(this is how loops work)
	movl	$10, %edi  #else just print a newline and push it as the argument to printf
	call	putchar  #call printf to print a newline (putchar)
	addl	$1, -4824(%rbp)  #increment i by 1 
.L2:
	movl	-4828(%rbp), %eax #push the variable n onto eadx
	cmpl	%eax, -4824(%rbp) #check if i<n
	jl	.L5  #if i<n then jump of L5(This is how looping works)
	movl	$0, %eax  #just clear the contents of %eax
	movq	-8(%rbp), %rcx #load stack guard from -8(%rbsp)
	xorq	%fs:40, %rcx #check if the stack is not corrupted
	je	.L7  #if not corrupted(XOR==0) then just jump to L7
	call	__stack_chk_fail
.L7:
	leave   #destroy the stack and the call pointer
	.cfi_def_cfa 7, 8
	ret  #just return back the call from where it came 
 	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	ReadMat
	.type	ReadMat, @function
ReadMat:
.LFB1:
	.cfi_startproc
	pushq	%rbp  #again just push the base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp #copy the base pointer to the stack pointer
	.cfi_def_cfa_register 6
	subq	$32, %rsp  #make space in memory for the storing the local variables
	movl	%edi, -20(%rbp) #store the value of n 
	movq	%rsi, -32(%rbp) #store the address of Matrix A 
	movl	$0, -8(%rbp) #initialise the variable i
	jmp	.L9  #unconditional jump to L9
.L12:
	movl	$0, -4(%rbp) #initialise j
	jmp	.L10 #unconditional jump to L10
.L11:
	movl	-8(%rbp), %eax #load i onto %eax
	movslq	%eax, %rdx #move sign extended double word(size is double of original)
	movq	%rdx, %rax #load the contents of rdx onto rax
	salq	$2, %rax #quadruple the contents of rax 
	addq	%rdx, %rax #replace the contents of rdx by the sum of rdx and rax 
	salq	$4, %rax #multiply the contents of rax by 16 
	movq	%rax, %rdx #load the contents of rdx onto rax
	movq	-32(%rbp), %rax #load the base address of matrix data in %rax
	addq	%rax, %rdx  #add the offset to the base address
	movl	-4(%rbp), %eax #load the variable j onto rax
	cltq    #convert %eax to quad
	salq	$2, %rax  #quadruple the contents of rax
	addq	%rdx, %rax #%rax stores the address of data[i][j]
	movq	%rax, %rsi #for the second argument of scanf which is simply the address
	movl	$.LC1, %edi #load %d as the first argument of scanf
	movl	$0, %eax #number of vector arguments
	call	__isoc99_scanf #another scanf call
	addl	$1, -4(%rbp) #increase the value of j by 1 
.L10:
	movl	-4(%rbp), %eax #move the variable j onto %eax
	cmpl	-20(%rbp), %eax #compare with the stored value of n 
	jl	.L11  #jump if j<n again how looping works
	addl	$1, -8(%rbp) #increase the value of i
.L9:
	movl	-8(%rbp), %eax #move variable i onto %eax
	cmpl	-20(%rbp), %eax #compare with the value of n stored
	jl	.L12  #if condition is satisfied then just jump to l12 this is how looping works
	nop   #no operation
	leave  #restore stack and frame pointers
	.cfi_def_cfa 7, 8
	ret  #return the control to from where the function was initally called 
	.cfi_endproc
.LFE1:
	.size	ReadMat, .-ReadMat
	.section	.rodata
	.align 8
.LC6:
	.string	"\nThe transpose of the second matrix:"
	.text
	.globl	TransMat
	.type	TransMat, @function
TransMat:
.LFB2:
	.cfi_startproc
	pushq	%rbp  #push the base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp #store the stack pointer
	.cfi_def_cfa_register 6
	subq	$32, %rsp  #make room for the local variables, grow the stack by 32 bytes
	movl	%edi, -20(%rbp) #store n in the address 20 bytes away from the base address
	movq	%rsi, -32(%rbp) #save the address of data in 32 bytes from the base pointer
	movl	$0, -12(%rbp) #outerloop parameter initalisation
	jmp	.L14 #unconditional jump to L14
.L17:
	movl	$0, -8(%rbp) #inner loop paramter intialisation
	jmp	.L15 #unconditional jump to L15
.L16:
	movl	-12(%rbp), %eax #copy i into %eax
	movslq	%eax, %rdx #move signed extended double word to %rdx(double the size of the original variable)
	movq	%rdx, %rax #load the contents of rdx onto rax
	salq	$2, %rax #quadruple the value of rax
	addq	%rdx, %rax #replace rax by the sum of rdx and rax 
	salq	$4, %rax  #multiply the value of rax by 16 
	movq	%rax, %rdx #load the value of rax onto rdx
	movq	-32(%rbp), %rax #the starting address of the matrix is stored in rax
	addq	%rax, %rdx #rdx is the starting address of the matrix
	movl	-8(%rbp), %eax #eax is the value of variable of j
	cltq    #converts %eax to a quad word
	movl	(%rdx,%rax,4), %eax #store the value of rdx+4*rax in eax 
	movl	%eax, -4(%rbp) #copy the value of eax to the variable t which is off by 4 bytes
	movl	-12(%rbp), %eax #save the value of j in %eax
	movslq	%eax, %rdx  #move the signed extended double word to %rdx(size is double of the original variable )
	movq	%rdx, %rax #load the contents of rdx onto rax 
	salq	$2, %rax #quadruple the contents of rax
	addq	%rdx, %rax #load the contents of rdx onto rax
	salq	$4, %rax #multiply the contents of rax by 16 
	movq	%rax, %rdx #load the contents of rax onto rdx
	movq	-32(%rbp), %rax #the base address of matrix
	leaq	(%rdx,%rax), %rcx #replace the contents of rsi by the sum of rdx and rax 
	movl	-8(%rbp), %eax #copy i onto eax
	movslq	%eax, %rdx #move signed extended double word to %rdx
	movq	%rdx, %rax #load the contents of rdx onto rax
	salq	$2, %rax #quadruple the contents of rax 
	addq	%rdx, %rax #replace the contents of rax by the sum of rdx and rax 
	salq	$4, %rax #multiply the contents of rax by 16 
	movq	%rax, %rdx #load the contents of rax onto rdx
	movq	-32(%rbp), %rax #the base address of matrix is stored in rax
	addq	%rax, %rdx #replace the contents of rdx by the sum of rdx and rax 
	movl	-12(%rbp), %eax  #eax stores the value of the variable i
	cltq     #converts eax into quadword
	movl	(%rdx,%rax,4), %edx #replace the value of edx by the sum of rsi and 4*rax
	movl	-8(%rbp), %eax  #eax stores the value of variable j 
	cltq    #convert eax into quadword
	movl	%edx, (%rcx,%rax,4)
	movl	-8(%rbp), %eax #load j onto eax
	movslq	%eax, %rdx #moved signed extended double word to rdx(double of the size of the original variable)
	movq	%rdx, %rax #load the contents of rdx onto rax
	salq	$2, %rax  #quadruple the value stored into rax
	addq	%rdx, %rax #replace the value of rax by the sum of rax and rdx 
	salq	$4, %rax #multiply the value stored in rax by 16 
	movq	%rax, %rdx  #load the contents of rax onto rdx
	movq	-32(%rbp), %rax #the base address of the matrix
	leaq	(%rdx,%rax), %rcx #rcx holds the address of data[j][0]
	movl	-12(%rbp), %eax #load the variable i in eax
	cltq     #convert eax to quadword
	movl	-4(%rbp), %edx  #load the value of t to edx
	movl	%edx, (%rcx,%rax,4) #replace the value in the matrix by rcx+4*rax
	addl	$1, -8(%rbp)  #increment the value of j
.L15:
	movl	-8(%rbp), %eax  #load the value of j in eax
	cmpl	-12(%rbp), %eax #compare if j<i
	jl	.L16     #jump to above this is how looping works 
	addl	$1, -12(%rbp)  #incrementation of i
.L14:
	movl	-12(%rbp), %eax  #load the value of i into eax
	cmpl	-20(%rbp), %eax  #check if i <n
	jl	.L17        #jump to l17 if condition satisifed this is how looping works
	movl	$.LC6, %edi  #break out of loop and call printf
	call	puts   #call to puts for the printing operation
	movl	$0, -12(%rbp) #initialise i with zero for second loop
	jmp	.L18  #unconditional jump to loop 18
.L21:
	movl	$0, -8(%rbp)  #inner loop parameter initialisation
	jmp	.L19  #unconditional jump to 19
.L20:
	movl	-12(%rbp), %eax  #load the value of i in eax
	movslq	%eax, %rdx #move signed extended double word of %rdx(double the size of the original variable)
	movq	%rdx, %rax  #move the contents of rdx onto rax
	salq	$2, %rax #quadruple the contents of rax 
	addq	%rdx, %rax  #replace rax by the sum of rdx and rax 
	salq	$4, %rax  #replace the contents of rax by 16 times the value of rax
	movq	%rax, %rdx #move the contents of rax onto rdx
	movq	-32(%rbp), %rax #load the base address onto rax
	addq	%rax, %rdx  #rdx is the starting point of the matrix
	movl	-8(%rbp), %eax #load the value of j in eax
	cltq    #convert eax to quadword
	movl	(%rdx,%rax,4), %eax #load eax with rdx+4*rax
	movl	%eax, %esi  #second argument to printf
	movl	$.LC5, %edi #first argument to printf
	movl	$0, %eax  #number of vector registers used 
	call	printf  #another call to printf
	addl	$1, -8(%rbp)  #increment j
.L19:
	movl	-8(%rbp), %eax #move j into eax
	cmpl	-20(%rbp), %eax #check if j<n
	jl	.L20  #jump to l20 if condition is true because this is how looping works
	movl	$10, %edi  #move newline character to %edi(argument to printf)
	call	putchar  #call printf for printing the newline
	addl	$1, -12(%rbp) #increment i 
.L18:
	movl	-12(%rbp), %eax #load the value of i onto eax
	cmpl	-20(%rbp), %eax #check if i<n
	jl	.L21  #if condition is true then jump to l21 because this is how looping works
	nop  #no operation otherwise
	leave #clear stack and base reference pointers
	.cfi_def_cfa 7, 8
	ret  #return to the caller from which the call was made 
	.cfi_endproc
.LFE2:
	.size	TransMat, .-TransMat
	.globl	VectMult
	.type	VectMult, @function
VectMult:
.LFB3:
	.cfi_startproc
	pushq	%rbp  #push the base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp  #save the value of base pointer to the stack pointer
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)# save the first argument in 20 bytes off the base pointer
	movq	%rsi, -32(%rbp)#save first matrix in 32 bytes off the base pointer
	movq	%rdx, -40(%rbp)#save second matrix in 40 bytes off the base pointer
	movl	$0, -4(%rbp) #the result is initalised to 0
	movl	$0, -8(%rbp) #loop parameter is initalised to zero
	jmp	.L23  #unconditional loop jump at L23 at the beginning of the loop
.L24:
	movl	-8(%rbp), %eax  #load the value of i onto eax
	cltq    #convert eax onto a quad word
	leaq	0(,%rax,4), %rdx #load the value of 4*rax onto rdx
	movq	-32(%rbp), %rax #save the first matrix onto rax
	addq	%rdx, %rax #rax  now points to the starting address of the first matrix
	movl	(%rax), %edx #edx contains the value of rax
	movl	-8(%rbp), %eax #load the value of i onto rax
	cltq     #converts eax into a quadword
	leaq	0(,%rax,4), %rcx #replace the value of rcx by 4 times the value of rax
	movq	-40(%rbp), %rax #save the starting address of the second matrix onto rax
	addq	%rcx, %rax #load the address of rax with the sum of addresses of rcx and rax 
	movl	(%rax), %eax #load the addrress of rax to eax
	imull	%edx, %eax #replace the value of eax by the product of values of eax and edx
	addl	%eax, -4(%rbp) #add eax to the result
	addl	$1, -8(%rbp) #incrementation of the loop variable i
.L23:
	movl	-8(%rbp), %eax #load the variable i in eax
	cmpl	-20(%rbp), %eax #check if i<n
	jl	.L24 #jump if the condition is satisfied because this is how looping works
	movl	-4(%rbp), %eax #else save result in eax for return
	popq	%rbp  #remove the base pointer(pop it out of the memory stack)
	.cfi_def_cfa 7, 8
	ret   #return to the function from where the call came
	.cfi_endproc
.LFE3:
	.size	VectMult, .-VectMult
	.globl	MatMult
	.type	MatMult, @function
MatMult:
.LFB4:
	.cfi_startproc
	pushq	%rbp  #push the base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp  #copy the stack pointer onto the base pointer
	.cfi_def_cfa_register 6
	pushq	%rbx #return the saved function
	subq	$56, %rsp #making space for the temporary variables
	.cfi_offset 3, -24
	movl	%edi, -36(%rbp) #copy n to a location 36 bytes off from the base location
	movq	%rsi, -48(%rbp) #copy address of the first matrix
	movq	%rdx, -56(%rbp)  #copy address of the second matrix
	movq	%rcx, -64(%rbp) #copy address of matrix M
	movq	-56(%rbp), %rdx #save starting address of M onto rdx
	movl	-36(%rbp), %eax  #load the value of n onto eax
	movq	%rdx, %rsi #address of second matrix
	movl	%eax, %edi #the variable N 
	call	TransMat #calling the transpose matrix function
	movl	$0, -24(%rbp) #initialise the outer variable parameter
	jmp	.L27  #unconditional jump 
.L30:
	movl	$0, -20(%rbp)  #initialise the inner variable parameter
	jmp	.L28  #unconditional jump
.L29:
	movl	-24(%rbp), %eax  #load the value of j onto eax
	movslq	%eax, %rdx  #move the signed extended double word to rdx(double the size of the original)
	movq	%rdx, %rax  #load the contents of rdx onto rax
	salq	$2, %rax    #quadruple the contents of rax 
	addq	%rdx, %rax  #replace the contents of rax by the sum of rax and rdx 
	salq	$4, %rax    #multiply the contents of rax by 16 
	movq	%rax, %rdx  #rdx now contains the starting address of the second matrix
	movq	-64(%rbp), %rax #store the base of second matrix in rax
	leaq	(%rdx,%rax), %rbx #rbx now stores the address of M[i][j]
	movl	-20(%rbp), %eax # load the value of j onto eax
	movslq	%eax, %rdx #move signed extended double word to rdx(double the size of the original word)
	movq	%rdx, %rax #load the contents of rdx onto rax
	salq	$2, %rax #quadruple the contents of rax 
	addq	%rdx, %rax  #replace the contents of rax by the sum of rdx and rax
	salq	$4, %rax  #multiply the value stored in rax by 16 
	movq	%rax, %rdx #load the contents of rax onto rdx
	movq	-56(%rbp), %rax #store the address of second matrix in rax
	addq	%rdx, %rax #rax has the starting address of the second matrix
	movq	%rax, %rsi #save the third argument for the call to vecmul
	movl	-24(%rbp), %eax  #load the value of i onto eax
	movslq	%eax, %rdx #moved signed extended double word to rdx(double the size of the original word)
	movq	%rdx, %rax #replace the contents of rax by rdx
	salq	$2, %rax  #quadruple the value of rax
	addq	%rdx, %rax  #replace the contents of rax by the sum of rax and rdx
	salq	$4, %rax  #replace the contents of rax by 16 times the value already stored
	movq	%rax, %rdx  #rdx now contains the starting address of the first matrix
	movq	-48(%rbp), %rax #store the base address of first matrix in rax
	addq	%rdx, %rax #rax has the base address of first[i][0]
	movq	%rax, %rcx #saving second argument of vectmul in rcx
	movl	-36(%rbp), %eax #load the value of i onto ax
	movq	%rsi, %rdx #3rd argument to vector mult
	movq	%rcx, %rsi #2nd arg to vector mult it was stored in rcx till now 
	movl	%eax, %edi  #first argument of vecmult i.e.the value of n 
	call	VectMult  #function call vector multiplication function
	movl	%eax, %edx #save the return value of vec mult in edx
	movl	-20(%rbp), %eax #load the value of j to eax
	cltq    #convert %eax from long to quadword
	movl	%edx, (%rbx,%rax,4) #extend the size of M by 4 bytes
	addl	$1, -20(%rbp)  #increment the value of j
.L28:
	movl	-20(%rbp), %eax #save the value of n in eax
	cmpl	-36(%rbp), %eax #check if i is less than n
	jl	.L29  #if condition true then jump to L29 because that is how looping works
	addl	$1, -24(%rbp) #increment i
.L27:
	movl	-24(%rbp), %eax  #load the value of n in eax
	cmpl	-36(%rbp), %eax  #check if j<n
	jl	.L30  #if condition satisfied then straight jump to L30 because that's how looping works
	nop  #else no operattion takes place
	addq	$56, %rsp #pop the temp address out of the memory stack
	popq	%rbx  #pop the callee out of the memory stack
	popq	%rbp #pop the base pointer of the memory stack
	.cfi_def_cfa 7, 8
	ret   #return to place from which the call was made 
	.cfi_endproc
.LFE4:
	.size	MatMult, .-MatMult
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.11) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
