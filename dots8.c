typedef volatile unsigned short hword;
#define VRAM 0x06000000

void draw_point (hword, hword, hword);

int main (void) {
	hword *ptr;
	hword color;

	ptr = (hword*) 0x04000000;
	*ptr = 0x0F03;
	color = 0x7FE0; // cyan

	hword x, y;
	for(y = 0; y < 320; y++){
		for(x = 0; x < 240; x++){
			draw_point(x ,y , color);
		}
	}
	while(1);
	return(0);
}

void draw_point (hword x , hword y , hword color) {
	hword *ptr = (hword*) (VRAM + x + 240*y);
	*ptr = color;
}
