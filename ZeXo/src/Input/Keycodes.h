#pragma once

/* The unknown key */
#define ZX_KEY_UNKNOWN            -1

/* Printable keys */
#define ZX_KEY_SPACE              32
#define ZX_KEY_APOSTROPHE         39  /* ' */
#define ZX_KEY_COMMA              44  /* , */
#define ZX_KEY_MINUS              45  /* - */
#define ZX_KEY_PERIOD             46  /* . */
#define ZX_KEY_SLASH              47  /* / */
#define ZX_KEY_0                  48
#define ZX_KEY_1                  49
#define ZX_KEY_2                  50
#define ZX_KEY_3                  51
#define ZX_KEY_4                  52
#define ZX_KEY_5                  53
#define ZX_KEY_6                  54
#define ZX_KEY_7                  55
#define ZX_KEY_8                  56
#define ZX_KEY_9                  57
#define ZX_KEY_SEMICOLON          59  /* ; */
#define ZX_KEY_EQUAL              61  /* = */
#define ZX_KEY_A                  65
#define ZX_KEY_B                  66
#define ZX_KEY_C                  67
#define ZX_KEY_D                  68
#define ZX_KEY_E                  69
#define ZX_KEY_F                  70
#define ZX_KEY_G                  71
#define ZX_KEY_H                  72
#define ZX_KEY_I                  73
#define ZX_KEY_J                  74
#define ZX_KEY_K                  75
#define ZX_KEY_L                  76
#define ZX_KEY_M                  77
#define ZX_KEY_N                  78
#define ZX_KEY_O                  79
#define ZX_KEY_P                  80
#define ZX_KEY_Q                  81
#define ZX_KEY_R                  82
#define ZX_KEY_S                  83
#define ZX_KEY_T                  84
#define ZX_KEY_U                  85
#define ZX_KEY_V                  86
#define ZX_KEY_W                  87
#define ZX_KEY_X                  88
#define ZX_KEY_Y                  89
#define ZX_KEY_Z                  90
#define ZX_KEY_LEFT_BRACKET       91  /* [ */
#define ZX_KEY_BACKSLASH          92  /* \ */
#define ZX_KEY_RIGHT_BRACKET      93  /* ] */
#define ZX_KEY_GRAVE_ACCENT       96  /* ` */
#define ZX_KEY_WORLD_1            161 /* non-US #1 */
#define ZX_KEY_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define ZX_KEY_ESCAPE             256
#define ZX_KEY_ENTER              257
#define ZX_KEY_TAB                258
#define ZX_KEY_BACKSPACE          259
#define ZX_KEY_INSERT             260
#define ZX_KEY_DELETE             261
#define ZX_KEY_RIGHT              262
#define ZX_KEY_LEFT               263
#define ZX_KEY_DOWN               264
#define ZX_KEY_UP                 265
#define ZX_KEY_PAGE_UP            266
#define ZX_KEY_PAGE_DOWN          267
#define ZX_KEY_HOME               268
#define ZX_KEY_END                269
#define ZX_KEY_CAPS_LOCK          280
#define ZX_KEY_SCROLL_LOCK        281
#define ZX_KEY_NUM_LOCK           282
#define ZX_KEY_PRINT_SCREEN       283
#define ZX_KEY_PAUSE              284
#define ZX_KEY_F1                 290
#define ZX_KEY_F2                 291
#define ZX_KEY_F3                 292
#define ZX_KEY_F4                 293
#define ZX_KEY_F5                 294
#define ZX_KEY_F6                 295
#define ZX_KEY_F7                 296
#define ZX_KEY_F8                 297
#define ZX_KEY_F9                 298
#define ZX_KEY_F10                299
#define ZX_KEY_F11                300
#define ZX_KEY_F12                301
#define ZX_KEY_F13                302
#define ZX_KEY_F14                303
#define ZX_KEY_F15                304
#define ZX_KEY_F16                305
#define ZX_KEY_F17                306
#define ZX_KEY_F18                307
#define ZX_KEY_F19                308
#define ZX_KEY_F20                309
#define ZX_KEY_F21                310
#define ZX_KEY_F22                311
#define ZX_KEY_F23                312
#define ZX_KEY_F24                313
#define ZX_KEY_F25                314
#define ZX_KEY_KP_0               320
#define ZX_KEY_KP_1               321
#define ZX_KEY_KP_2               322
#define ZX_KEY_KP_3               323
#define ZX_KEY_KP_4               324
#define ZX_KEY_KP_5               325
#define ZX_KEY_KP_6               326
#define ZX_KEY_KP_7               327
#define ZX_KEY_KP_8               328
#define ZX_KEY_KP_9               329
#define ZX_KEY_KP_DECIMAL         330
#define ZX_KEY_KP_DIVIDE          331
#define ZX_KEY_KP_MULTIPLY        332
#define ZX_KEY_KP_SUBTRACT        333
#define ZX_KEY_KP_ADD             334
#define ZX_KEY_KP_ENTER           335
#define ZX_KEY_KP_EQUAL           336
#define ZX_KEY_LEFT_SHIFT         340
#define ZX_KEY_LEFT_CONTROL       341
#define ZX_KEY_LEFT_ALT           342
#define ZX_KEY_LEFT_SUPER         343
#define ZX_KEY_RIGHT_SHIFT        344
#define ZX_KEY_RIGHT_CONTROL      345
#define ZX_KEY_RIGHT_ALT          346
#define ZX_KEY_RIGHT_SUPER        347
#define ZX_KEY_MENU               348

#define ZX_KEY_LAST               ZX_KEY_MENU

#define ZX_MOUSE_BUTTON_1         0
#define ZX_MOUSE_BUTTON_2         1
#define ZX_MOUSE_BUTTON_3         2
#define ZX_MOUSE_BUTTON_4         3
#define ZX_MOUSE_BUTTON_5         4
#define ZX_MOUSE_BUTTON_6         5
#define ZX_MOUSE_BUTTON_7         6
#define ZX_MOUSE_BUTTON_8         7
#define ZX_MOUSE_BUTTON_LAST      ZX_MOUSE_BUTTON_8
#define ZX_MOUSE_BUTTON_LEFT      ZX_MOUSE_BUTTON_1
#define ZX_MOUSE_BUTTON_RIGHT     ZX_MOUSE_BUTTON_2
#define ZX_MOUSE_BUTTON_MIDDLE    ZX_MOUSE_BUTTON_3

#define ZX_JOYSTICK_1             0
#define ZX_JOYSTICK_2             1
#define ZX_JOYSTICK_3             2
#define ZX_JOYSTICK_4             3
#define ZX_JOYSTICK_5             4
#define ZX_JOYSTICK_6             5
#define ZX_JOYSTICK_7             6
#define ZX_JOYSTICK_8             7
#define ZX_JOYSTICK_9             8
#define ZX_JOYSTICK_10            9
#define ZX_JOYSTICK_11            10
#define ZX_JOYSTICK_12            11
#define ZX_JOYSTICK_13            12
#define ZX_JOYSTICK_14            13
#define ZX_JOYSTICK_15            14
#define ZX_JOYSTICK_16            15
#define ZX_JOYSTICK_LAST          ZX_JOYSTICK_16

#define ZX_GAMEPAD_BUTTON_A               0
#define ZX_GAMEPAD_BUTTON_B               1
#define ZX_GAMEPAD_BUTTON_X               2
#define ZX_GAMEPAD_BUTTON_Y               3
#define ZX_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define ZX_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define ZX_GAMEPAD_BUTTON_BACK            6
#define ZX_GAMEPAD_BUTTON_START           7
#define ZX_GAMEPAD_BUTTON_GUIDE           8
#define ZX_GAMEPAD_BUTTON_LEFT_THUMB      9
#define ZX_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define ZX_GAMEPAD_BUTTON_DPAD_UP         11
#define ZX_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define ZX_GAMEPAD_BUTTON_DPAD_DOWN       13
#define ZX_GAMEPAD_BUTTON_DPAD_LEFT       14
#define ZX_GAMEPAD_BUTTON_LAST            ZX_GAMEPAD_BUTTON_DPAD_LEFT

#define ZX_GAMEPAD_BUTTON_CROSS       ZX_GAMEPAD_BUTTON_A
#define ZX_GAMEPAD_BUTTON_CIRCLE      ZX_GAMEPAD_BUTTON_B
#define ZX_GAMEPAD_BUTTON_SQUARE      ZX_GAMEPAD_BUTTON_X
#define ZX_GAMEPAD_BUTTON_TRIANGLE    ZX_GAMEPAD_BUTTON_Y

#define ZX_GAMEPAD_AXIS_LEFT_X        0
#define ZX_GAMEPAD_AXIS_LEFT_Y        1
#define ZX_GAMEPAD_AXIS_RIGHT_X       2
#define ZX_GAMEPAD_AXIS_RIGHT_Y       3
#define ZX_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define ZX_GAMEPAD_AXIS_RIGHT_TRIGGER 5
#define ZX_GAMEPAD_AXIS_LAST          ZX_GAMEPAD_AXIS_RIGHT_TRIGGER