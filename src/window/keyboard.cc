#include <window/keyboard.h>
#include <window/opengl.h>

#include <cstring>

window::keyboard::key window::keyboard::glfw_to_key(int key)
{
    switch(key)
    {
        case GLFW_KEY_UNKNOWN:                   return key::unknown;       
        case GLFW_KEY_SPACE:                     return key::space;         
        case GLFW_KEY_APOSTROPHE:                return key::apostrophe;    
        case GLFW_KEY_COMMA:                     return key::comma;         
        case GLFW_KEY_MINUS:                     return key::minus;         
        case GLFW_KEY_PERIOD:                    return key::period;        
        case GLFW_KEY_SLASH:                     return key::slash;         
        case GLFW_KEY_0:                         return key::zero;          
        case GLFW_KEY_1:                         return key::one;           
        case GLFW_KEY_2:                         return key::two;           
        case GLFW_KEY_3:                         return key::three;         
        case GLFW_KEY_4:                         return key::four;          
        case GLFW_KEY_5:                         return key::five;          
        case GLFW_KEY_6:                         return key::six;           
        case GLFW_KEY_7:                         return key::seven;         
        case GLFW_KEY_8:                         return key::eight;         
        case GLFW_KEY_9:                         return key::nine;          
        case GLFW_KEY_SEMICOLON:                 return key::semicolon;     
        case GLFW_KEY_EQUAL:                     return key::equal;         
        case GLFW_KEY_A:                         return key::a;             
        case GLFW_KEY_B:                         return key::b;             
        case GLFW_KEY_C:                         return key::c;             
        case GLFW_KEY_D:                         return key::d;             
        case GLFW_KEY_E:                         return key::e;             
        case GLFW_KEY_F:                         return key::f;             
        case GLFW_KEY_G:                         return key::g;             
        case GLFW_KEY_H:                         return key::h;             
        case GLFW_KEY_I:                         return key::i;             
        case GLFW_KEY_J:                         return key::j;             
        case GLFW_KEY_K:                         return key::k;             
        case GLFW_KEY_L:                         return key::l;             
        case GLFW_KEY_M:                         return key::m;             
        case GLFW_KEY_N:                         return key::n;             
        case GLFW_KEY_O:                         return key::o;             
        case GLFW_KEY_P:                         return key::p;             
        case GLFW_KEY_Q:                         return key::q;             
        case GLFW_KEY_R:                         return key::r;             
        case GLFW_KEY_S:                         return key::s;             
        case GLFW_KEY_T:                         return key::t;             
        case GLFW_KEY_U:                         return key::u;             
        case GLFW_KEY_V:                         return key::v;             
        case GLFW_KEY_W:                         return key::w;             
        case GLFW_KEY_X:                         return key::x;             
        case GLFW_KEY_Y:                         return key::y;             
        case GLFW_KEY_Z:                         return key::z;             
        case GLFW_KEY_LEFT_BRACKET:              return key::left_bracket;  
        case GLFW_KEY_BACKSLASH:                 return key::backslash;     
        case GLFW_KEY_RIGHT_BRACKET:             return key::right_bracket; 
        case GLFW_KEY_GRAVE_ACCENT:              return key::grave_accent;  
        case GLFW_KEY_WORLD_1:                   return key::world_1;       
        case GLFW_KEY_WORLD_2:                   return key::world_2;       
        case GLFW_KEY_ESCAPE:                    return key::escape;        
        case GLFW_KEY_ENTER:                     return key::enter;         
        case GLFW_KEY_TAB:                       return key::tab;           
        case GLFW_KEY_BACKSPACE:                 return key::backspace;     
        case GLFW_KEY_INSERT:                    return key::insert;        
        case GLFW_KEY_DELETE:                    return key::del;           
        case GLFW_KEY_RIGHT:                     return key::right;         
        case GLFW_KEY_LEFT:                      return key::left;          
        case GLFW_KEY_DOWN:                      return key::down;          
        case GLFW_KEY_UP:                        return key::up;            
        case GLFW_KEY_PAGE_UP:                   return key::page_up;       
        case GLFW_KEY_PAGE_DOWN:                 return key::page_down;     
        case GLFW_KEY_HOME:                      return key::home;          
        case GLFW_KEY_END:                       return key::end;           
        case GLFW_KEY_CAPS_LOCK:                 return key::caps_lock;     
        case GLFW_KEY_SCROLL_LOCK:               return key::scroll_lock;   
        case GLFW_KEY_NUM_LOCK:                  return key::num_lock;      
        case GLFW_KEY_PRINT_SCREEN:              return key::print_screen;  
        case GLFW_KEY_PAUSE:                     return key::pause;         
        case GLFW_KEY_F1:                        return key::F1;            
        case GLFW_KEY_F2:                        return key::F2;            
        case GLFW_KEY_F3:                        return key::F3;            
        case GLFW_KEY_F4:                        return key::F4;            
        case GLFW_KEY_F5:                        return key::F5;            
        case GLFW_KEY_F6:                        return key::F6;            
        case GLFW_KEY_F7:                        return key::F7;            
        case GLFW_KEY_F8:                        return key::F8;            
        case GLFW_KEY_F9:                        return key::F9;            
        case GLFW_KEY_F10:                       return key::F10;           
        case GLFW_KEY_F11:                       return key::F11;           
        case GLFW_KEY_F12:                       return key::F12;           
        case GLFW_KEY_F13:                       return key::F13;           
        case GLFW_KEY_F14:                       return key::F14;           
        case GLFW_KEY_F15:                       return key::F15;           
        case GLFW_KEY_F16:                       return key::F16;           
        case GLFW_KEY_F17:                       return key::F17;           
        case GLFW_KEY_F18:                       return key::F18;           
        case GLFW_KEY_F19:                       return key::F19;           
        case GLFW_KEY_F20:                       return key::F20;           
        case GLFW_KEY_F21:                       return key::F21;           
        case GLFW_KEY_F22:                       return key::F22;           
        case GLFW_KEY_F23:                       return key::F23;           
        case GLFW_KEY_F24:                       return key::F24;           
        case GLFW_KEY_F25:                       return key::F25;           
        case GLFW_KEY_KP_0:                      return key::kp_0;          
        case GLFW_KEY_KP_1:                      return key::kp_1;          
        case GLFW_KEY_KP_2:                      return key::kp_2;          
        case GLFW_KEY_KP_3:                      return key::kp_3;          
        case GLFW_KEY_KP_4:                      return key::kp_4;          
        case GLFW_KEY_KP_5:                      return key::kp_5;          
        case GLFW_KEY_KP_6:                      return key::kp_6;          
        case GLFW_KEY_KP_7:                      return key::kp_7;          
        case GLFW_KEY_KP_8:                      return key::kp_8;          
        case GLFW_KEY_KP_9:                      return key::kp_9;          
        case GLFW_KEY_KP_DECIMAL:                return key::kp_decimal;    
        case GLFW_KEY_KP_DIVIDE:                 return key::kp_divide;     
        case GLFW_KEY_KP_MULTIPLY:               return key::kp_multiply;   
        case GLFW_KEY_KP_SUBTRACT:               return key::kp_subtract;   
        case GLFW_KEY_KP_ADD:                    return key::kp_add;        
        case GLFW_KEY_KP_ENTER:                  return key::kp_enter;      
        case GLFW_KEY_KP_EQUAL:                  return key::kp_equal;      
        case GLFW_KEY_LEFT_SHIFT:                return key::left_shift;    
        case GLFW_KEY_LEFT_CONTROL:              return key::left_control;  
        case GLFW_KEY_LEFT_ALT:                  return key::left_alt;      
        case GLFW_KEY_LEFT_SUPER:                return key::left_super;    
        case GLFW_KEY_RIGHT_SHIFT:               return key::right_shift;   
        case GLFW_KEY_RIGHT_CONTROL:             return key::right_control; 
        case GLFW_KEY_RIGHT_ALT:                 return key::right_alt;     
        case GLFW_KEY_RIGHT_SUPER:               return key::right_super;   
        case GLFW_KEY_MENU:                      return key::menu;          
        default:                                 return key::unknown;
    };
}

int window::keyboard::key_to_glfw(key key)
{
    switch(key)
    {
        case key::unknown:       return GLFW_KEY_UNKNOWN;
        case key::space:         return GLFW_KEY_SPACE;
        case key::apostrophe:    return GLFW_KEY_APOSTROPHE;
        case key::comma:         return GLFW_KEY_COMMA;
        case key::minus:         return GLFW_KEY_MINUS;
        case key::period:        return GLFW_KEY_PERIOD;
        case key::slash:         return GLFW_KEY_SLASH;
        case key::zero:          return GLFW_KEY_0;
        case key::one:           return GLFW_KEY_1;
        case key::two:           return GLFW_KEY_2;
        case key::three:         return GLFW_KEY_3;
        case key::four:          return GLFW_KEY_4;
        case key::five:          return GLFW_KEY_5;
        case key::six:           return GLFW_KEY_6;
        case key::seven:         return GLFW_KEY_7;
        case key::eight:         return GLFW_KEY_8;
        case key::nine:          return GLFW_KEY_9;
        case key::semicolon:     return GLFW_KEY_SEMICOLON;
        case key::equal:         return GLFW_KEY_EQUAL;
        case key::a:             return GLFW_KEY_A;
        case key::b:             return GLFW_KEY_B;
        case key::c:             return GLFW_KEY_C;
        case key::d:             return GLFW_KEY_D;
        case key::e:             return GLFW_KEY_E;
        case key::f:             return GLFW_KEY_F;
        case key::g:             return GLFW_KEY_G;
        case key::h:             return GLFW_KEY_H;
        case key::i:             return GLFW_KEY_I;
        case key::j:             return GLFW_KEY_J;
        case key::k:             return GLFW_KEY_K;
        case key::l:             return GLFW_KEY_L;
        case key::m:             return GLFW_KEY_M;
        case key::n:             return GLFW_KEY_N;
        case key::o:             return GLFW_KEY_O;
        case key::p:             return GLFW_KEY_P;
        case key::q:             return GLFW_KEY_Q;
        case key::r:             return GLFW_KEY_R;
        case key::s:             return GLFW_KEY_S;
        case key::t:             return GLFW_KEY_T;
        case key::u:             return GLFW_KEY_U;
        case key::v:             return GLFW_KEY_V;
        case key::w:             return GLFW_KEY_W;
        case key::x:             return GLFW_KEY_X;
        case key::y:             return GLFW_KEY_Y;
        case key::z:             return GLFW_KEY_Z;
        case key::left_bracket:  return GLFW_KEY_LEFT_BRACKET;
        case key::backslash:     return GLFW_KEY_BACKSLASH;
        case key::right_bracket: return GLFW_KEY_RIGHT_BRACKET;
        case key::grave_accent:  return GLFW_KEY_GRAVE_ACCENT;
        case key::world_1:       return GLFW_KEY_WORLD_1;
        case key::world_2:       return GLFW_KEY_WORLD_2;
        case key::escape:        return GLFW_KEY_ESCAPE;
        case key::enter:         return GLFW_KEY_ENTER;
        case key::tab:           return GLFW_KEY_TAB;
        case key::backspace:     return GLFW_KEY_BACKSPACE;
        case key::insert:        return GLFW_KEY_INSERT;
        case key::del:           return GLFW_KEY_DELETE;
        case key::right:         return GLFW_KEY_RIGHT;
        case key::left:          return GLFW_KEY_LEFT;
        case key::down:          return GLFW_KEY_DOWN;
        case key::up:            return GLFW_KEY_UP;
        case key::page_up:       return GLFW_KEY_PAGE_UP;
        case key::page_down:     return GLFW_KEY_PAGE_DOWN;
        case key::home:          return GLFW_KEY_HOME;
        case key::end:           return GLFW_KEY_END;
        case key::caps_lock:     return GLFW_KEY_CAPS_LOCK;
        case key::scroll_lock:   return GLFW_KEY_SCROLL_LOCK;
        case key::num_lock:      return GLFW_KEY_NUM_LOCK;
        case key::print_screen:  return GLFW_KEY_PRINT_SCREEN;
        case key::pause:         return GLFW_KEY_PAUSE;
        case key::F1:            return GLFW_KEY_F1;
        case key::F2:            return GLFW_KEY_F2;
        case key::F3:            return GLFW_KEY_F3;
        case key::F4:            return GLFW_KEY_F4;
        case key::F5:            return GLFW_KEY_F5;
        case key::F6:            return GLFW_KEY_F6;
        case key::F7:            return GLFW_KEY_F7;
        case key::F8:            return GLFW_KEY_F8;
        case key::F9:            return GLFW_KEY_F9;
        case key::F10:           return GLFW_KEY_F10;
        case key::F11:           return GLFW_KEY_F11;
        case key::F12:           return GLFW_KEY_F12;
        case key::F13:           return GLFW_KEY_F13;
        case key::F14:           return GLFW_KEY_F14;
        case key::F15:           return GLFW_KEY_F15;
        case key::F16:           return GLFW_KEY_F16;
        case key::F17:           return GLFW_KEY_F17;
        case key::F18:           return GLFW_KEY_F18;
        case key::F19:           return GLFW_KEY_F19;
        case key::F20:           return GLFW_KEY_F20;
        case key::F21:           return GLFW_KEY_F21;
        case key::F22:           return GLFW_KEY_F22;
        case key::F23:           return GLFW_KEY_F23;
        case key::F24:           return GLFW_KEY_F24;
        case key::F25:           return GLFW_KEY_F25;
        case key::kp_0:          return GLFW_KEY_KP_0;
        case key::kp_1:          return GLFW_KEY_KP_1;
        case key::kp_2:          return GLFW_KEY_KP_2;
        case key::kp_3:          return GLFW_KEY_KP_3;
        case key::kp_4:          return GLFW_KEY_KP_4;
        case key::kp_5:          return GLFW_KEY_KP_5;
        case key::kp_6:          return GLFW_KEY_KP_6;
        case key::kp_7:          return GLFW_KEY_KP_7;
        case key::kp_8:          return GLFW_KEY_KP_8;
        case key::kp_9:          return GLFW_KEY_KP_9;
        case key::kp_decimal:    return GLFW_KEY_KP_DECIMAL;
        case key::kp_divide:     return GLFW_KEY_KP_DIVIDE;
        case key::kp_multiply:   return GLFW_KEY_KP_MULTIPLY;
        case key::kp_subtract:   return GLFW_KEY_KP_SUBTRACT;
        case key::kp_add:        return GLFW_KEY_KP_ADD;
        case key::kp_enter:      return GLFW_KEY_KP_ENTER;
        case key::kp_equal:      return GLFW_KEY_KP_EQUAL;
        case key::left_shift:    return GLFW_KEY_LEFT_SHIFT;
        case key::left_control:  return GLFW_KEY_LEFT_CONTROL;
        case key::left_alt:      return GLFW_KEY_LEFT_ALT;
        case key::left_super:    return GLFW_KEY_LEFT_SUPER;
        case key::right_shift:   return GLFW_KEY_RIGHT_SHIFT;
        case key::right_control: return GLFW_KEY_RIGHT_CONTROL;
        case key::right_alt:     return GLFW_KEY_RIGHT_ALT;
        case key::right_super:   return GLFW_KEY_RIGHT_SUPER;
        case key::menu:          return GLFW_KEY_MENU;
        case key::last:          return GLFW_KEY_UNKNOWN;
    };
}

void window::keyboard::on_event(int glfw_key, int, int action, int)
{
    key k = glfw_to_key(glfw_key);
    if(k == key::unknown) return; //safety check

    key_state& state = _keys[(int)k];

    if(action == GLFW_RELEASE)
    {
        if(state.pressed)
            state.went_up = true;
        state.pressed = false;
        state.repeat = false;
    }
    else if(action == GLFW_PRESS)
    {
        if(!state.pressed)
            state.went_down = true;
        state.pressed = true;
    }
    else if(action == GLFW_REPEAT)
    {
        state.repeat = true;
    }
}

void window::keyboard::begin_frame()
{
    for(int i=0;i<(int)key::last;++i)
    {
        _keys[i].went_up = false;
        _keys[i].went_down = false;
        _keys[i].repeat = false;
    }
}

window::keyboard::keyboard()
{
    memset(_keys, 0, sizeof(_keys));
}