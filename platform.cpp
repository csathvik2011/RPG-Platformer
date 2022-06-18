#include <windows.h>

bool running = true;

LRESULT CALLBACK WindowProc window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
      LRESULT result = 0;
      
      switch (uMsg) {
      case WM_CLOSE:
      case WM_DESTROY: {
            running = false;
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
          while (running) {
            // Input
            MSG message;
            while(PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
                  TranslateMessage(&message)
                  DispatchMessage(&message)
            }
           // Simulate
         
          // Render
}
