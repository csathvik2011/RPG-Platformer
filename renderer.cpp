void render_background() {
   unsigned int* pixel = (unsigned int)buffer_memory;
           for (int y = 0; y < buffer_height; y++) {
                 for (int x = 0; x < buffer_width; y++) {
                       *pixel++ = 0xff00ff;
                 }
           }
}
