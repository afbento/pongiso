#include<stdio.h>
#asm
	._tiles_1
	defb 0,0,0,0,0,0,0,0
	defb 144,36,9,2,0,0,0,0
	defb 0,0,0,64,144,36,9,2
	defb 0,0,0,2,9,36,144,64
	defb 9,36,144,64,0,0,0,0
	._tiles_2
	defb 240,124,31,7,1,0,0,0
	defb 0,0,0,192,240,124,31,7
	defb 0,0,0,3,15,62,248,224
	defb 15,62,248,224,128,0,0,0
	defb 0,0,0,0,0,0,0,3
	defb 0,0,0,0,0,0,0,192
	._tiles_3
	defb 64,0,4,0,0,0,0,0
	defb 0,0,0,0,64,0,4,0
	defb 0,0,0,0,0,8,0,128
	defb 0,8,0,128,0,0,0,0
	
	._sprite_1
	defb 96,248,254,127,31,7,1,0,0,0,0,0,0,0,0,0,0,0,0,128,224,248,254,127,31,6,0,0,0,0,0,0
	._sprite_2
	defb 0,0,0,0,0,0,1,3,3,1,0,0,0,0,0,0,0,0,0,0,0,0,128,192,192,128,0,0,0,0,0,0
	
	._di
	defb 1,12,2,13,32,10,33,11,34,8,35,9,36,13,64,8,65,9,66,18,67,19,68,8,69,9,98,8,99,9,100,10,101,11
	defb 1,0,2,13,32,18,33,19,34,8,35,9,36,13,64,16,65,17,66,18,67,19,68,8,69,9,98,16,99,17,100,18,101,19
	defb 1,12,2,13,32,10,33,11,34,8,35,9,36,0,64,16,65,17,66,10,67,11,68,16,69,17,98,8,99,9,100,10,101,11
	defb 1,12,2,13,32,10,33,11,34,8,35,9,36,13,64,16,65,17,66,10,67,11,68,8,69,9,98,16,99,17,100,10,101,11
	defb 1,0,2,13,32,18,33,19,34,8,35,9,36,13,64,8,65,9,66,10,67,11,68,8,69,9,98,16,99,17,100,18,101,19
	defb 1,12,2,0,32,10,33,11,34,16,35,17,36,13,64,8,65,9,66,10,67,11,68,8,69,9,98,16,99,17,100,10,101,11
	defb 1,12,2,0,32,10,33,11,34,16,35,17,36,13,64,8,65,9,66,10,67,11,68,8,69,9,98,8,99,9,100,10,101,11
	defb 1,12,2,13,32,10,33,11,34,8,35,9,36,13,64,16,65,17,66,18,67,19,68,8,69,9,98,16,99,17,100,18,101,19
	defb 1,12,2,13,32,10,33,11,34,8,35,9,36,13,64,8,65,9,66,10,67,11,68,8,69,9,98,8,99,9,100,10,101,11
	defb 1,12,2,13,32,10,33,11,34,8,35,9,36,13,64,8,65,9,66,10,67,11,68,8,69,9,98,16,99,17,100,10,101,11
	defb 1,12,2,13,32,10,33,11,34,8,35,9,36,13,64,8,65,9,66,10,67,11,68,16,69,17,98,8,99,9,100,18,101,19
	defb 1,12,2,13,32,10,33,11,34,8,35,9,36,13,64,8,65,9,66,18,67,19,68,8,69,9,98,8,99,9,100,18,101,19
	defb 1,12,2,0,32,10,33,11,34,16,35,17,36,13,64,8,65,9,66,18,67,19,68,8,69,9,98,8,99,9,100,10,101,11
#endasm	

int ai,ai1,p1,p2,x1,y1,x2,y2,x3,y3,xx,yy,yyy,xk,spd,spd1,spd2;

char sp1,sp2,sp3,sp4,cort;


main() 
{



#asm
	ld a,32
	ld (0xF3AF),a // width32
	call 0x6F     // screen 1
	
	//sprite 16x16 e mag=0
	ld a,(0xF3E0) 
    or 2
	res 0,a 
    ld b,a
    ld c,1
    call 0x47

	ld a,1
	ld (0xF3EA),a
	ld (0xF3EB),a
	ld a,15
	ld (0xF3E9),a
	call 0x62     // color 15,1,1

	ld a,0
	ld(0xF3DB),a  // keyoff
	
	ld hl,_tiles_1
	ld de,0x0 
	ld bc,8*5
	call 0x5C     // fori=0to8*5-1:reada:vpokei,a:next
	
	ld hl,_tiles_2
	ld de,8*8 
	ld bc,8*6
	call 0x5C     // fori=0to8*6-1:reada:vpokei+8*8,a:next
	
	ld hl,_tiles_3
	ld de,16*8 
	ld bc,8*4
	call 0x5C     // fori=0to8*4-1:reada:vpokei+16*8,a:next
	
	ld a,0xf1
	ld hl,0x2000
	call 0x4d    // vpoke&h2000,&hf1
	
	ld a,0x81
	ld hl,0x2001
	call 0x4d    // vpoke&h2001,&h81
	
	ld a,0x41
	ld hl,0x2002
	call 0x4d    // vpoke&h2001,&h41
	
	._abert
	
	call 0x69  //clrspr
	
	ld hl,_sprite_1
	ld de,0x3800 
	ld bc,32
	call 0x5C    // fori=0to31:reada:b$=b$+chr$(a):next:sprite$(0)=b$
	
	ld hl,_sprite_2
	ld de,0x3800+32 
	ld bc,32
	call 0x5C    // fori=0to31:reada:c$=c$+chr$(a):next:sprite$(1)=c$
	
	xor a
	call 0xc3     // cls

    ld a,10
	ld hl,0x1800+10*32+7
	ld (_ai),hl
	call _display // fori=0to16:vpoke&h1800+di(10,i*2)+10*32+7,di(10,i*2+1):next

	ld a,0
	ld hl,0x1800+8*32+11
	ld (_ai),hl
	call _display // fori=0to16:vpoke&h1800+di(0,i*2)+8*32+11,di(0,i*2+1):next
	
	ld a,11
	ld hl,0x1800+6*32+15
	ld (_ai),hl
	call _display // fori=0to16:vpoke&h1800+di(11,i*2)+6*32+15,di(11,i*2+1):next
	
	ld a,12
	ld hl,0x1800+4*32+19
	ld (_ai),hl
	call _display // fori=0to16:vpoke&h1800+di(12,i*2)+4*32+19,di(12,i*2+1):next

	ld hl,0
	._dly_abert
	inc hl
	call 0xd8
	ld a,h
	cp 0x60
	jr nz,_dly_abert

	xor a
	call 0xc3     // cls
	ld a,0
	ld (_p1),a
	ld (_p2),a
	
	ld b,10
	ld hl,0x1800+448
   ._loop1
	ld a,3
	call 0x4d    
	push hl
	inc hl
	ld a,4
	call 0x4d
	ld de,652-449
	add hl,de
	ld a,3
	call 0x4d
	inc hl
	ld a,4
	call 0x4d
	pop hl
	ld de,30
	sbc hl,de
	djnz _loop1    // fori=0to9:vpoke&h1800+448-i*30,3:vpoke&h1800+449-i*30,4:vpoke&h1800+652-i*30,3:vpoke&h1800+653-i*30,4:next
	
	ld b,6
	ld hl,0x1800+180
   ._loop2
	ld a,1
	call 0x4d
	push hl
	inc hl
	ld a,2
	call 0x4d
	ld de,330-181
	add hl,de
	ld a,1
	call 0x4d
	inc hl
	ld a,2
	call 0x4d
	ld de,480-331
	add hl,de
	ld a,1
	call 0x4d
	inc hl
	ld a,2
	call 0x4d
	pop hl
	ld de,34
	add hl,de
	djnz _loop2      //fori=0to5:vpoke&h1800+480+i*34,1:vpoke&h1800+481+i*34,2:vpoke&h1800+330+i*34,1:vpoke&h1800+331+i*34,2:vpoke&h1800+180+i*34,1:vpoke&h1800+181+i*34,2:next

	ld a,0
	ld (_xx),a
	ld a,1
	ld (_yy),a

   ._inic_j	
	ld a,(_p1)
	ld hl,0x1800+18*32
	ld (_ai),hl
	call _display    //fori=0to16:vpoke&h1800+di(p1,i*2)+18*32,di(p1,i*2+1):next
	
	ld a,(_p2)
	ld hl,0x1800+3*32+26
	ld (_ai),hl
	call _display    //fori=0to16:vpoke&h1800+di(p2,i*2)+3*32+26,di(p2,i*2+1):next
 
	ld a,45
	ld (_x1),a
	ld a,130
	ld (_y1),a
	ld a,195
	ld (_x2),a
	ld a,65
	ld (_y2),a
	ld a,120
	ld (_x3),a
	ld a,88
	ld (_y3),a     //x1=45:y1=130:x2=195:y2=65:x3=120:y3=88:v=3:xx=0:yy=v
	
	ld a,10
	ld (_spd),a
	ld (_spd1),a
	ld a,20
	ld (_spd2),a
	
   ._loop_pr

	ld a,(_y1)
	dec a
	ld (_sp1),a
	ld a,(_x1)
	ld (_sp2),a
	ld a,0*2
	ld (_sp3),a
	ld a,15
	ld (_sp4),a
	ld hl,_sp1
	ld de,0x1b00
	ld bc,4
	call 0x5c	     //putsprite 0,(x1,y1),15,0
	
	ld a,(_y2)
	dec a
	ld (_sp1),a
	ld a,(_x2)
	ld (_sp2),a
	ld hl,_sp1
	ld de,0x1b00+4
	ld bc,4
	call 0x5c	     //putsprite 1,(x2,y2),15,0
	
	ld a,(_y3)
	dec a
	ld (_sp1),a
	ld a,(_x3)
	ld (_sp2),a
	ld a,1*4
	ld (_sp3),a
	//ld a,(_cort)
	//ld (_sp4),a
	ld hl,_sp1
	ld de,0x1b00+8
	ld bc,4
	call 0x5c	     //putsprite 2,(x3,y3),15,1

	ld a,(_spd1)
	cp 0
	jp nz,_skp_spd1
	ld a,20
	ld (_spd1),a
	
	ld a,1
	call 0xd5  //GTSTCK
	ld b,a
	ld a,0
	call 0xd5  //GTSTCK
	or b
	ld d,a
	cp 3
	jr nz,_ndir1
	ld a,(_x1)
	cp 89
	jr nc,_ndir1
	inc a
	inc a
	ld (_x1),a
	ld a,(_y1)
	inc a
	ld (_y1),a
   ._ndir1	
    ld a,d
	cp 7
	jr nz,_nesq1
	ld a,(_x1)
	cp 14
	jr c,_nesq1
	dec a
	dec a
	ld (_x1),a
	ld a,(_y1)
	dec a
	ld (_y1),a
   ._nesq1	      //j=stick(0):ifj=3andx1<89thenx1=x1+2:y1=y1+1:end:ifj=7andx1>11thenx1=x1-2:y1=y1-1:end

 	ld a,5
	ld b,0
	call 0x0141    //SNSMAT
	bit 7,a
	jr nz,_jp1
	ld b,7
   ._jp1
	bit 5,a
	jr nz,_jp2
	ld b,3
   ._jp2
	push bc
	ld a,2
	call 0xd5      //GTSTCK
	pop bc
	or b
	ld d,a
	cp 3
	jr nz,_ndir2
	ld a,(_x2)
	cp 229
	jr nc,_ndir2
	inc a
	inc a
	ld (_x2),a
	ld a,(_y2)
	inc a
	ld (_y2),a
   ._ndir2	
    ld a,d
	cp 7
	jr nz,_nesq2
	ld a,(_x2)
	cp 154
	jr c,_nesq2
	dec a
	dec a
	ld (_x2),a
	ld a,(_y2)
	dec a
	ld (_y2),a
   ._nesq2	      //j=stick(1):ifj=3andx2<229thenx2=x2+2:y2=y2+1:end:ifj=7andx2>151thenx2=x2-2:y2=y2-1:end

	._skp_spd1
	ld a,(_spd1)
	dec a
	ld (_spd1),a   // spd1 = delay para paddles
	
	ld a,(_spd)
	cp 0
	jr nz,_skp_spd
	ld a,(_spd2)
	ld (_spd),a
	
	ld a,(_xx)
	ld b,a
	ld a,(_x3)
	add a,b
	ld (_x3),a     //x3=x3+xx
	
	ld a,(_yyy)
	cp 0
	jr nz,_j_yy1
	ld a,(_yy)
	ld b,a
	ld a,(_y3)
	add a,b
	ld (_y3),a     //y3=y3+yy
	ld a,1
	ld (_yyy),a
	jr _j_yy2
	._j_yy1
	ld a,0
	ld (_yyy),a
	._j_yy2
	
	._skp_spd
	ld a,(_spd)
	dec a
	ld (_spd),a      // spd = delay para bola
	
    ld a,(_x3)
	ld d,a
	ld e,2
	
	xor	a
	ld b,8
   ._loop_div
	sla d
	rla
	cp e
	jr c,_j_div
	sub e
	inc d
   ._j_div
	djnz _loop_div    
	
	ld a,d
	
	ld (_xk),a    // xk=x3/2
	neg
	ld d,200
	add a,d
	ld c,a
	ld a,(_y3)
	cp c
	jr c,_nequ1
	ld a,(_x3)
	cp 90
	jr c,_nequ1
	ld a,(_yy)
	cp 1
	jr nz,_nequ12
	ld a,-1
	ld(_xx),a
	ld a,0
	ld (_yy),a
	._nequ12
	ld a,(_xx)
	cp 1
	jr nz,_nequ1
	ld a,0
	ld(_xx),a
	ld a,-1
	ld (_yy),a
	._nequ1
	
	ld a,(_xk)
	neg
	ld d,112
	add a,d
	ld c,a
	ld a,(_y3)
	cp c
	jr nc,_nequ2
	ld a,(_x3)
	cp 152
	jr nc,_nequ2
	ld a,(_yy)
	cp -1
	jr nz,_nequ22
	ld a,1
	ld(_xx),a
	ld a,0
	ld (_yy),a
	._nequ22
	ld a,(_xx)
	cp -1
	jr nz,_nequ2
	ld a,0
	ld(_xx),a
	ld a,1
	ld (_yy),a
	._nequ2
	
	ld a,(0xf3e7)
	and 32
	jr z,_nequ3
	ld a,(_x3)
	cp 128
	jr nc,_nequ3
	ld a,(_xk)
	ld d,118-10
	add a,d
	ld c,a
	ld a,(_y3)
	cp c
	jr nc,_nequ3
	ld a,(_xx)
	cp -1
	jr nz,_nequ33
	ld a,0
	ld(_xx),a
	ld a,-1
	ld (_yy),a
	ld a,(_spd2)
	dec a
	ld (_spd2),a
	._nequ33
	ld a,(_yy)
	cp 1
	jr nz,_nequ3
	ld a,1
	ld(_xx),a
	ld a,0
	ld (_yy),a
	ld a,(_spd2)
	dec a
	ld (_spd2),a
	._nequ3	
	
	
	ld a,(0xf3e7)
	and 32
	jr z,_nequ4
	ld a,(_x3)
	cp 128
	jr c,_nequ4
	ld a,(_xk)
	ld d,-45+10
	add a,d
	ld c,a
	ld a,(_y3)
	cp c
	jr c,_nequ4
	ld a,(_xx)
	cp 1
	jr nz,_nequ44
	ld a,0
	ld(_xx),a
	ld a,1
	ld (_yy),a
	ld a,(_spd2)
	dec a
	ld (_spd2),a
	._nequ44
	ld a,(_yy)
	cp -1
	jr nz,_nequ4
	ld a,-1
	ld(_xx),a
	ld a,0
	ld (_yy),a
	ld a,(_spd2)
	dec a
	ld (_spd2),a
	._nequ4
	
	ld a,(_xk)
	ld d,118-5
	add a,d
	ld c,a
	ld a,(_y3)
	cp c
	jr c,_nequ5
	ld a,(_x3)
	cp 88
	jr nc,_nequ5
	ld a,(_p2)
	inc a
	ld (_p2),a
	ld a,0
	ld (_xx),a
	ld a,-1
	ld (_yy),a
	jp _inic_j
	._nequ5
	
	ld a,(_xk)
	ld d,-45+5
	add a,d
	ld c,a
	ld a,(_y3)
	cp c
	jr nc,_nequ6
	ld a,(_x3)
	cp 152
	jr c,_nequ6
	ld a,(_p1)
	inc a
	ld (_p1),a
	ld a,0
	ld (_xx),a
	ld a,1
	ld (_yy),a
	jp _inic_j
	._nequ6
	
	ld a,(_p1)
	cp 9
	jr nz,_skp_end1
	ld hl,0
	._dly_abert1
	inc hl
	call 0xd8
	ld a,h
	cp 0x60
	jr nz,_dly_abert1
	jp _abert
	
	._skp_end1
	ld a,(_p2)
	cp 9
	jr nz,_skp_end2
	ld hl,0
	._dly_abert2
	inc hl
	call 0xd8
	ld a,h
	cp 0x60
	jr nz,_dly_abert2
	jp _abert
	
	._skp_end2
	
	ld a,(_spd2)       // spd2 = velocidade da bola
	cp 5
	jr nc,_nspd_lim
	ld a,5
	ld (_spd2),a
	._nspd_lim
	
	jp _loop_pr

	ret
	
   ._display      //rotina do display - a=valor, _ai=posição na tela
	ld hl,0
	cp 0
	jr z,_dig_zero
	ld b,a
	ld de,34
   ._id_di
	add hl,de
	djnz _id_di
   ._dig_zero	
	ex de,hl
	ld hl,_di
	add hl,de
	ld b,17
   ._loop_di
	ld a,(hl)
	ld e,a
	inc hl
	ld a,(hl)
	inc hl
	push hl
	ld hl,(_ai)
	ld d,0
	add hl,de
	call 0x4d
	pop hl
	djnz _loop_di	
	ret
	
#endasm 
	
}
	