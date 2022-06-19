#include <windows.h>

bool running = true;
struct Render_State {
      int height, width;
      void* memory
      
      BITMAPINFO bitmapinfo;
};

Render_State render_state;

LRESULT CALLBACK WindowProc window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
      LRESULT result = 0;
      
      switch (uMsg) {
      case WM_CLOSE:
      case WM_DESTROY: {
            running = false;
            } break;  
                  
            case WM_SIZE: {
                  RECT rect;
                  GetClientRect(hwnd, &rect);
                  buffer_width = rect.right - rect.left;
                  buffer_height = rect.bottom - rect.top
                        
                  int buffer_size = buffer_width * buffer_height * sizeof(unsigned int);
                  
                  if (buffer_memory) VirtualFree(buffer_memory, 0, MEM_RELEASE);
                  buffer_memory = VirtualAlloc(0, buffer_size, MEM COMMIT | MEM_RESERVE, PAGE_READWRITE);
                 
                  buffer_bitmap_info.bmiHeader.biSize = sizeof(buffer_bitmap_info.bmiHeader)
                  buffer_bitmap_info.bmiHeader.biWidth = buffer_width;
                  buffer_bitmap_info.bmiHeader.biHeight = buffer_height;
                  buffer_bitmap_info.bmiHeader.biPlanes = 1;
                  buffer_bitmap_info.bmiHeader.biBitCount = 32;
                  buffer_bitmap_info.bmiHeader.biCompression = BI_RGB;
                 
            } break;
                  
            default: {
               result = DefWindowProc(hwnd, uMsg, wParam, lParam)   
            }       
      }
      return result;
}      

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
      // Create Window Class
      WNDCLASS window_class = {};
      window_class.style = CS_HREDRAW | CS_VREDRAW;
      window_class.lpszClassName = "Game Window Class";
      window_class.lpfnWndProc = window_callback;
      // Register Classs 
      RegisterClass(&window_class);
      // Create Window
    HWND window = CreateWindow(window_class.lpszClassName, "My First Game!", WS_OVERLAPPEWINDOW | WS_Visible, CWUSEDEFAULT, CWUSEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
    HDC hdc = GetDC(window);
          while (running) {
            // Input
            MSG message;
            while(PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
                  TranslateMessage(&message)
                  DispatchMessage(&message)
            }
           // Simulate
           unsigned int* pixel = (unsigned int)buffer_memory;
           for (int y = 0; y < buffer_height; y++) {
                 for (int x = 0; x < buffer_width; y++) {
                       *pixel++ = 0xff00ff;
                 }
           }
          // Render
          StretchDIBits(hdc, 0, 0, buffer_width, buffer_height, 0, 0, buffer_width, buffer_height, buffer_memory, &buffer_bitmap_info, DIB_RGB_COLORS, SRCCOPY);
      }

      
}
