void render_background() {
   unsigned int* pixel = (unsigned int)buffer_memory;
           for (int y = 0; y < buffer_height; y++) {
                 for (int x = 0; x < buffer_width; y++) {
                       *pixel++ = 0xff00ff;
                 }
           }
}

void clear_screen(unsigned int color) {
   unsigned int* pixel = (unsigned int)buffer_memory;
           for (int y = 0; y < buffer_height; y++) {
                 for (int x = 0; x < buffer_width; y++) {
                       *pixel++ = color;
                 }
           }
}

void draw_rect(int x0, int y0, int x1, int y1, unsigned int color) {

   x0 = clamp(0, x0, buffer_width)
   x1 = clamp(0, x1, buffer_width)
   y0 = clamp(0, y0, buffer_height)
   y1 = clamp(0, y1, buffer_height)
   
   
   for (int y = 0; y < buffer_height; y++) {
      unsigned int* pixel = (unsigned int)buffer_memory + x0 + y*buffer_width;
                 for (int x = 0; x < buffer_width; y++) {
                       *pixel++ = 0xff00ff;
                 }
           }
}
