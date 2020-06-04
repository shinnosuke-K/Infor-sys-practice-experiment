typedef volatile unsigned short hword;
#define VRAM 0x06000000

void draw_point (hword, hword, hword);

int main (void) {
	hword *ptr ;
	hword cyan;
	hword red;
	hword x;
	hword y;
	hword *key;

	key = (hword*) 0x04000130;
	ptr = (hword*) 0x04000000;
	*ptr = 0x0F03;
	cyan = 0x7FE0; // cyan
	red  = 0x001F; // red

	for(y = 0; y < 160; y++){
		for(x = 0; x < 240; x++){
			draw_point(x ,y , cyan);
		}
	}

	x = ((525) + (3)) % 59 + 60;
	y = (525) * (3) % 39 + 81;
	draw_point(x, y , red);

	while(1){
		if((*key&0x0010) == 0x0000) {
			draw_point(x, y , cyan);
			x +=1;
			draw_point(x, y , red);
		} else if((*key&0x0020) == 0x0000) {
			draw_point(x, y , cyan);
			x -=1;
			draw_point(x, y , red);
		} else if((*key&0x0040) == 0x0000) {
			draw_point(x, y , cyan);
			y -=1;
			draw_point(x, y , red);
		} else if((*key&0x0080) == 0x0000) {
			draw_point(x, y , cyan);
			y +=1;
			draw_point(x, y , red);
		}
		int i;
		for(i = 0; i < 5000; i++);
	};
	return(0);
}

void draw_point (hword x , hword y , hword color) {
	hword *ptr = (hword*)VRAM;
	ptr +=(x + y*240);
	*ptr = color;
}

