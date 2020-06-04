typedef volatile unsigned short hword;
#define VRAM 0x06000000
void draw_point (hword, hword, hword);

int main (void) {
	hword *ptr ;
	ptr = (hword*) 0x04000000;
	*ptr = 0x0F03;

	hword xe = (525)*(3) % 19 +101;
	hword ye = (1028) % 19 + 61;
	hword r  = (1032) % 9 +29;

	hword red  = 0x7FE0;
	hword cyan = 0x001F;

	hword x, y;
	for(y =0 ; y < 160; y++){
		for(x = 0; x < 240; x++){
			if(r*r >=(xe - x)*(xe - x) + (ye - y)*(ye -y)){
				draw_point(x ,y , cyan);
			}else{
				draw_point(x ,y , red);
			}
		}
	}
	while(1);
	return(0);
}

void draw_point (hword x , hword y , hword color) {
	hword *ptr = (hword*)VRAM;
	ptr +=(x + y*240);
	*ptr = color;
}





