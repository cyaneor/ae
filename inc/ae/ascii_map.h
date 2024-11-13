/**
 * @file ascii_map.h
 * @brief Заголовочный файл, содержащий определения символов ASCII.
 *
 * Этот файл определяет макросы для всех символов ASCII от 0 до 127,
 * включая управляющие символы, пробелы, цифры, буквы и специальные символы.
 * Каждый макрос представляет собой символ, соответствующий его коду ASCII,
 * что позволяет легко использовать их в коде.
 */

#ifndef AE_ASCII_MAP_H
#define AE_ASCII_MAP_H

/**
 * @def AE_ASCII_MAP_NULL_TERMINATOR
 * @brief Символ завершения строки (NULL).
 */
#define AE_ASCII_MAP_NULL_TERMINATOR '\0'

/**
 * @def AE_ASCII_MAP_CONTROL_1
 * @brief Управляющий символ 1 (ASCII 0x01).
 */
#define AE_ASCII_MAP_CONTROL_1 '\x01'

/**
 * @def AE_ASCII_MAP_CONTROL_2
 * @brief Управляющий символ 2 (ASCII 0x02).
 */
#define AE_ASCII_MAP_CONTROL_2 '\x02'

/**
 * @def AE_ASCII_MAP_CONTROL_3
 * @brief Управляющий символ 3 (ASCII 0x03).
 */
#define AE_ASCII_MAP_CONTROL_3 '\x03'

/**
 * @def AE_ASCII_MAP_CONTROL_4
 * @brief Управляющий символ 4 (ASCII 0x04).
 */
#define AE_ASCII_MAP_CONTROL_4 '\x04'

/**
 * @def AE_ASCII_MAP_CONTROL_5
 * @brief Управляющий символ 5 (ASCII 0x05).
 */
#define AE_ASCII_MAP_CONTROL_5 '\x05'

/**
 * @def AE_ASCII_MAP_CONTROL_6
 * @brief Управляющий символ 6 (ASCII 0x06).
 */
#define AE_ASCII_MAP_CONTROL_6 '\x06'

/**
 * @def AE_ASCII_MAP_BELL
 * @brief Символ "звонок" (ASCII 0x07).
 */
#define AE_ASCII_MAP_BELL '\x07'

/**
 * @def AE_ASCII_MAP_BACKSPACE
 * @brief Символ "удаление" (ASCII 0x08).
 */
#define AE_ASCII_MAP_BACKSPACE '\x08'

/**
 * @def AE_ASCII_MAP_TAB
 * @brief Символ табуляции (ASCII 0x09).
 */
#define AE_ASCII_MAP_TAB '\t'

/**
 * @def AE_ASCII_MAP_NEWLINE
 * @brief Символ новой строки (ASCII 0x0A).
 */
#define AE_ASCII_MAP_NEWLINE '\n'

/**
 * @def AE_ASCII_MAP_VERTICAL_TAB
 * @brief Символ вертикальной табуляции (ASCII 0x0B).
 */
#define AE_ASCII_MAP_VERTICAL_TAB '\x0B'

/**
 * @def AE_ASCII_MAP_FORM_FEED
 * @brief Символ перевода страницы (ASCII 0x0C).
 */
#define AE_ASCII_MAP_FORM_FEED '\x0C'

/**
 * @def AE_ASCII_MAP_CARRIAGE_RETURN
 * @brief Символ возврата каретки (ASCII 0x0D).
 */
#define AE_ASCII_MAP_CARRIAGE_RETURN '\r'

/**
 * @def AE_ASCII_MAP_SHIFT_OUT
 * @brief Символ "выход из сдвига" (ASCII 0x0E).
 */
#define AE_ASCII_MAP_SHIFT_OUT '\x0E'

/**
 * @def AE_ASCII_MAP_SHIFT_IN
 * @brief Символ "вход в сдвиг" (ASCII 0x0F).
 */
#define AE_ASCII_MAP_SHIFT_IN '\x0F'

/**
 * @def AE_ASCII_MAP_DATA_LINK_ESCAPE
 * @brief Символ "ссылка на данные" (ASCII 0x10).
 */
#define AE_ASCII_MAP_DATA_LINK_ESCAPE '\x10'

/**
 * @def AE_ASCII_MAP_DEVICE_CONTROL_1
 * @brief Управляющий символ 1 для устройства (ASCII 0x11).
 */
#define AE_ASCII_MAP_DEVICE_CONTROL_1 '\x11'

/**
 * @def AE_ASCII_MAP_DEVICE_CONTROL_2
 * @brief Управляющий символ 2 для устройства (ASCII 0x12).
 */
#define AE_ASCII_MAP_DEVICE_CONTROL_2 '\x12'

/**
 * @def AE_ASCII_MAP_DEVICE_CONTROL_3
 * @brief Управляющий символ 3 для устройства (ASCII 0x13).
 */
#define AE_ASCII_MAP_DEVICE_CONTROL_3 '\x13'

/**
 * @def AE_ASCII_MAP_DEVICE_CONTROL_4
 * @brief Управляющий символ 4 для устройства (ASCII 0x14).
 */
#define AE_ASCII_MAP_DEVICE_CONTROL_4 '\x14'

/**
 * @def AE_ASCII_MAP_NEGATIVE_ACKNOWLEDGE
 * @brief Символ отрицательного подтверждения (ASCII 0x15).
 */
#define AE_ASCII_MAP_NEGATIVE_ACKNOWLEDGE '\x15'

/**
 * @def AE_ASCII_MAP_SYNCHRONOUS_IDLE
 * @brief Символ синхронного простоя (ASCII 0x16).
 */
#define AE_ASCII_MAP_SYNCHRONOUS_IDLE '\x16'

/**
 * @def AE_ASCII_MAP_END_OF_TRANSMISSION_BLOCK
 * @brief Символ конца блока передачи (ASCII 0x17).
 */
#define AE_ASCII_MAP_END_OF_TRANSMISSION_BLOCK '\x17'

/**
 * @def AE_ASCII_MAP_CANCEL
 * @brief Символ отмены (ASCII 0x18).
 */
#define AE_ASCII_MAP_CANCEL '\x18'

/**
 * @def AE_ASCII_MAP_END_OF_MEDIUM
 * @brief Символ конца носителя (ASCII 0x19).
 */
#define AE_ASCII_MAP_END_OF_MEDIUM '\x19'

/**
 * @def AE_ASCII_MAP_SUBSTITUTE
 * @brief Символ замены (ASCII 0x1A).
 */
#define AE_ASCII_MAP_SUBSTITUTE '\x1A'

/**
 * @def AE_ASCII_MAP_ESCAPE
 * @brief Символ экранирования (ASCII 0x1B).
 */
#define AE_ASCII_MAP_ESCAPE '\x1B'

/**
 * @def AE_ASCII_MAP_FILE_SEPARATOR
 * @brief Символ разделителя файлов (ASCII 0x1C).
 */
#define AE_ASCII_MAP_FILE_SEPARATOR '\x1C'

/**
 * @def AE_ASCII_MAP_GROUP_SEPARATOR
 * @brief Символ разделителя групп (ASCII 0x1D).
 */
#define AE_ASCII_MAP_GROUP_SEPARATOR '\x1D'

/**
 * @def AE_ASCII_MAP_RECORD_SEPARATOR
 * @brief Символ разделителя записей (ASCII 0x1E).
 */
#define AE_ASCII_MAP_RECORD_SEPARATOR '\x1E'

/**
 * @def AE_ASCII_MAP_UNIT_SEPARATOR
 * @brief Символ разделителя единиц (ASCII 0x1F).
 */
#define AE_ASCII_MAP_UNIT_SEPARATOR '\x1F'

/**
 * @def AE_ASCII_MAP_SPACE
 * @brief Символ пробела (ASCII 0x20).
 */
#define AE_ASCII_MAP_SPACE ' '

/**
 * @def AE_ASCII_MAP_EXCLAMATION_MARK
 * @brief Символ восклицательного знака (ASCII 0x21).
 */
#define AE_ASCII_MAP_EXCLAMATION_MARK '!'

/**
 * @def AE_ASCII_MAP_QUOTE
 * @brief Символ кавычки (ASCII 0x22).
 */
#define AE_ASCII_MAP_QUOTE '\"'

/**
 * @def AE_ASCII_MAP_HASH
 * @brief Символ решетки (ASCII 0x23).
 */
#define AE_ASCII_MAP_HASH '#'

/**
 * @def AE_ASCII_MAP_DOLLAR
 * @brief Символ доллара (ASCII 0x24).
 */
#define AE_ASCII_MAP_DOLLAR '$'

/**
 * @def AE_ASCII_MAP_PERCENT
 * @brief Символ процента (ASCII 0x25).
 */
#define AE_ASCII_MAP_PERCENT '%'

/**
 * @def AE_ASCII_MAP_AMPERSAND
 * @brief Символ амперсанда (ASCII 0x26).
 */
#define AE_ASCII_MAP_AMPERSAND '&'

/**
 * @def AE_ASCII_MAP_SINGLE_QUOTE
 * @brief Символ одинарной кавычки (ASCII 0x27).
 */
#define AE_ASCII_MAP_SINGLE_QUOTE '\''

/**
 * @def AE_ASCII_MAP_LEFT_PARENTHESIS
 * @brief Символ левой скобки (ASCII 0x28).
 */
#define AE_ASCII_MAP_LEFT_PARENTHESIS '('

/**
 * @def AE_ASCII_MAP_RIGHT_PARENTHESIS
 * @brief Символ правой скобки (ASCII 0x29).
 */
#define AE_ASCII_MAP_RIGHT_PARENTHESIS ')'

/**
 * @def AE_ASCII_MAP_ASTERISK
 * @brief Символ звездочки (ASCII 0x2A).
 */
#define AE_ASCII_MAP_ASTERISK '*'

/**
 * @def AE_ASCII_MAP_PLUS
 * @brief Символ плюса (ASCII 0x2B).
 */
#define AE_ASCII_MAP_PLUS '+'

/**
 * @def AE_ASCII_MAP_COMMA
 * @brief Символ запятой (ASCII 0x2C).
 */
#define AE_ASCII_MAP_COMMA ','

/**
 * @def AE_ASCII_MAP_HYPHEN
 * @brief Символ дефиса (ASCII 0x2D).
 */
#define AE_ASCII_MAP_HYPHEN '-'

/**
 * @def AE_ASCII_MAP_PERIOD
 * @brief Символ точки (ASCII 0x2E).
 */
#define AE_ASCII_MAP_PERIOD '.'

/**
 * @def AE_ASCII_MAP_SLASH
 * @brief Символ косой черты (ASCII 0x2F).
 */
#define AE_ASCII_MAP_SLASH '/'

/**
 * @def AE_ASCII_MAP_DIGIT_0
 * @brief Символ цифры 0 (ASCII 0x30).
 */
#define AE_ASCII_MAP_DIGIT_0 '0'

/**
 * @def AE_ASCII_MAP_DIGIT_1
 * @brief Символ цифры 1 (ASCII 0x31).
 */
#define AE_ASCII_MAP_DIGIT_1 '1'

/**
 * @def AE_ASCII_MAP_DIGIT_2
 * @brief Символ цифры 2 (ASCII 0x32).
 */
#define AE_ASCII_MAP_DIGIT_2 '2'

/**
 * @def AE_ASCII_MAP_DIGIT_3
 * @brief Символ цифры 3 (ASCII 0x33).
 */
#define AE_ASCII_MAP_DIGIT_3 '3'

/**
 * @def AE_ASCII_MAP_DIGIT_4
 * @brief Символ цифры 4 (ASCII 0x34).
 */
#define AE_ASCII_MAP_DIGIT_4 '4'

/**
 * @def AE_ASCII_MAP_DIGIT_5
 * @brief Символ цифры 5 (ASCII 0x35).
 */
#define AE_ASCII_MAP_DIGIT_5 '5'

/**
 * @def AE_ASCII_MAP_DIGIT_6
 * @brief Символ цифры 6 (ASCII 0x36).
 */
#define AE_ASCII_MAP_DIGIT_6 '6'

/**
 * @def AE_ASCII_MAP_DIGIT_7
 * @brief Символ цифры 7 (ASCII 0x37).
 */
#define AE_ASCII_MAP_DIGIT_7 '7'

/**
 * @def AE_ASCII_MAP_DIGIT_8
 * @brief Символ цифры 8 (ASCII 0x38).
 */
#define AE_ASCII_MAP_DIGIT_8 '8'

/**
 * @def AE_ASCII_MAP_DIGIT_9
 * @brief Символ цифры 9 (ASCII 0x39).
 */
#define AE_ASCII_MAP_DIGIT_9 '9'

/**
 * @def AE_ASCII_MAP_COLON
 * @brief Символ двоеточия (ASCII 0x3A).
 */
#define AE_ASCII_MAP_COLON ':'

/**
 * @def AE_ASCII_MAP_SEMICOLON
 * @brief Символ точки с запятой (ASCII 0x3B).
 */
#define AE_ASCII_MAP_SEMICOLON ';'

/**
 * @def AE_ASCII_MAP_LESS_THAN
 * @brief Символ меньше (ASCII 0x3C).
 */
#define AE_ASCII_MAP_LESS_THAN '<'

/**
 * @def AE_ASCII_MAP_EQUAL
 * @brief Символ равенства (ASCII 0x3D).
 */
#define AE_ASCII_MAP_EQUAL '='

/**
 * @def AE_ASCII_MAP_GREATER_THAN
 * @brief Символ больше (ASCII 0x3E).
 */
#define AE_ASCII_MAP_GREATER_THAN '>'

/**
 * @def AE_ASCII_MAP_QUESTION_MARK
 * @brief Символ вопросительного знака (ASCII 0x3F).
 */
#define AE_ASCII_MAP_QUESTION_MARK '?'

/**
 * @def AE_ASCII_MAP_AT
 * @brief Символ собачки (ASCII 0x40).
 */
#define AE_ASCII_MAP_AT '@'

/**
 * @def AE_ASCII_MAP_UPPERCASE_A
 * @brief Символ заглавной буквы A (ASCII 0x41).
 */
#define AE_ASCII_MAP_UPPERCASE_A 'A'

/**
 * @def AE_ASCII_MAP_UPPERCASE_B
 * @brief Символ заглавной буквы B (ASCII 0x42).
 */
#define AE_ASCII_MAP_UPPERCASE_B 'B'

/**
 * @def AE_ASCII_MAP_UPPERCASE_C
 * @brief Символ заглавной буквы C (ASCII 0x43).
 */
#define AE_ASCII_MAP_UPPERCASE_C 'C'

/**
 * @def AE_ASCII_MAP_UPPERCASE_D
 * @brief Символ заглавной буквы D (ASCII 0x44).
 */
#define AE_ASCII_MAP_UPPERCASE_D 'D'

/**
 * @def AE_ASCII_MAP_UPPERCASE_E
 * @brief Символ заглавной буквы E (ASCII 0x45).
 */
#define AE_ASCII_MAP_UPPERCASE_E 'E'

/**
 * @def AE_ASCII_MAP_UPPERCASE_F
 * @brief Символ заглавной буквы F (ASCII 0x46).
 */
#define AE_ASCII_MAP_UPPERCASE_F 'F'

/**
 * @def AE_ASCII_MAP_UPPERCASE_G
 * @brief Символ заглавной буквы G (ASCII 0x47).
 */
#define AE_ASCII_MAP_UPPERCASE_G 'G'

/**
 * @def AE_ASCII_MAP_UPPERCASE_H
 * @brief Символ заглавной буквы H (ASCII 0x48).
 */
#define AE_ASCII_MAP_UPPERCASE_H 'H'

/**
 * @def AE_ASCII_MAP_UPPERCASE_I
 * @brief Символ заглавной буквы I (ASCII 0x49).
 */
#define AE_ASCII_MAP_UPPERCASE_I 'I'

/**
 * @def AE_ASCII_MAP_UPPERCASE_J
 * @brief Символ заглавной буквы J (ASCII 0x4A).
 */
#define AE_ASCII_MAP_UPPERCASE_J 'J'

/**
 * @def AE_ASCII_MAP_UPPERCASE_K
 * @brief Символ заглавной буквы K (ASCII 0x4B).
 */
#define AE_ASCII_MAP_UPPERCASE_K 'K'

/**
 * @def AE_ASCII_MAP_UPPERCASE_L
 * @brief Символ заглавной буквы L (ASCII 0x4C).
 */
#define AE_ASCII_MAP_UPPERCASE_L 'L'

/**
 * @def AE_ASCII_MAP_UPPERCASE_M
 * @brief Символ заглавной буквы M (ASCII 0x4D).
 */
#define AE_ASCII_MAP_UPPERCASE_M 'M'

/**
 * @def AE_ASCII_MAP_UPPERCASE_N
 * @brief Символ заглавной буквы N (ASCII 0x4E).
 */
#define AE_ASCII_MAP_UPPERCASE_N 'N'

/**
 * @def AE_ASCII_MAP_UPPERCASE_O
 * @brief Символ заглавной буквы O (ASCII 0x4F).
 */
#define AE_ASCII_MAP_UPPERCASE_O 'O'

/**
 * @def AE_ASCII_MAP_UPPERCASE_P
 * @brief Символ заглавной буквы P (ASCII 0x50).
 */
#define AE_ASCII_MAP_UPPERCASE_P 'P'

/**
 * @def AE_ASCII_MAP_UPPERCASE_Q
 * @brief Символ заглавной буквы Q (ASCII 0x51).
 */
#define AE_ASCII_MAP_UPPERCASE_Q 'Q'

/**
 * @def AE_ASCII_MAP_UPPERCASE_R
 * @brief Символ заглавной буквы R (ASCII 0x52).
 */
#define AE_ASCII_MAP_UPPERCASE_R 'R'

/**
 * @def AE_ASCII_MAP_UPPERCASE_S
 * @brief Символ заглавной буквы S (ASCII 0x53).
 */
#define AE_ASCII_MAP_UPPERCASE_S 'S'

/**
 * @def AE_ASCII_MAP_UPPERCASE_T
 * @brief Символ заглавной буквы T (ASCII 0x54).
 */
#define AE_ASCII_MAP_UPPERCASE_T 'T'

/**
 * @def AE_ASCII_MAP_UPPERCASE_U
 * @brief Символ заглавной буквы U (ASCII 0x55).
 */
#define AE_ASCII_MAP_UPPERCASE_U 'U'

/**
 * @def AE_ASCII_MAP_UPPERCASE_V
 * @brief Символ заглавной буквы V (ASCII 0x56).
 */
#define AE_ASCII_MAP_UPPERCASE_V 'V'

/**
 * @def AE_ASCII_MAP_UPPERCASE_W
 * @brief Символ заглавной буквы W (ASCII 0x57).
 */
#define AE_ASCII_MAP_UPPERCASE_W 'W'

/**
 * @def AE_ASCII_MAP_UPPERCASE_X
 * @brief Символ заглавной буквы X (ASCII 0x58).
 */
#define AE_ASCII_MAP_UPPERCASE_X 'X'

/**
 * @def AE_ASCII_MAP_UPPERCASE_Y
 * @brief Символ заглавной буквы Y (ASCII 0x59).
 */
#define AE_ASCII_MAP_UPPERCASE_Y 'Y'

/**
 * @def AE_ASCII_MAP_UPPERCASE_Z
 * @brief Символ заглавной буквы Z (ASCII 0x5A).
 */
#define AE_ASCII_MAP_UPPERCASE_Z 'Z'

/**
 * @def AE_ASCII_MAP_LEFT_BRACKET
 * @brief Символ левой квадратной скобки (ASCII 0x5B).
 */
#define AE_ASCII_MAP_LEFT_BRACKET '['

/**
 * @def AE_ASCII_MAP_BACKSLASH
 * @brief Символ обратной косой черты (ASCII 0x5C).
 */
#define AE_ASCII_MAP_BACKSLASH '\\'

/**
 * @def AE_ASCII_MAP_RIGHT_BRACKET
 * @brief Символ правой квадратной скобки (ASCII 0x5D).
 */
#define AE_ASCII_MAP_RIGHT_BRACKET ']'

/**
 * @def AE_ASCII_MAP_CARET
 * @brief Символ каретки (ASCII 0x5E).
 */
#define AE_ASCII_MAP_CARET '^'

/**
 * @def AE_ASCII_MAP_UNDERLINE
 * @brief Символ подчеркивания (ASCII 0x5F).
 */
#define AE_ASCII_MAP_UNDERLINE '_'

/**
 * @def AE_ASCII_MAP_GRAVE
 * @brief Символ грависа (ASCII 0x60).
 */
#define AE_ASCII_MAP_GRAVE '`'

/**
 * @def AE_ASCII_MAP_LOWERCASE_A
 * @brief Символ строчной буквы a (ASCII 0x61).
 */
#define AE_ASCII_MAP_LOWERCASE_A 'a'

/**
 * @def AE_ASCII_MAP_LOWERCASE_B
 * @brief Символ строчной буквы b (ASCII 0x62).
 */
#define AE_ASCII_MAP_LOWERCASE_B 'b'

/**
 * @def AE_ASCII_MAP_LOWERCASE_C
 * @brief Символ строчной буквы c (ASCII 0x63).
 */
#define AE_ASCII_MAP_LOWERCASE_C 'c'

/**
 * @def AE_ASCII_MAP_LOWERCASE_D
 * @brief Символ строчной буквы d (ASCII 0x64).
 */
#define AE_ASCII_MAP_LOWERCASE_D 'd'

/**
 * @def AE_ASCII_MAP_LOWERCASE_E
 * @brief Символ строчной буквы e (ASCII 0x65).
 */
#define AE_ASCII_MAP_LOWERCASE_E 'e'

/**
 * @def AE_ASCII_MAP_LOWERCASE_F
 * @brief Символ строчной буквы f (ASCII 0x66).
 */
#define AE_ASCII_MAP_LOWERCASE_F 'f'

/**
 * @def AE_ASCII_MAP_LOWERCASE_G
 * @brief Символ строчной буквы g (ASCII 0x67).
 */
#define AE_ASCII_MAP_LOWERCASE_G 'g'

/**
 * @def AE_ASCII_MAP_LOWERCASE_H
 * @brief Символ строчной буквы h (ASCII 0x68).
 */
#define AE_ASCII_MAP_LOWERCASE_H 'h'

/**
 * @def AE_ASCII_MAP_LOWERCASE_I
 * @brief Символ строчной буквы i (ASCII 0x69).
 */
#define AE_ASCII_MAP_LOWERCASE_I 'i'

/**
 * @def AE_ASCII_MAP_LOWERCASE_J
 * @brief Символ строчной буквы j (ASCII 0x6A).
 */
#define AE_ASCII_MAP_LOWERCASE_J 'j'

/**
 * @def AE_ASCII_MAP_LOWERCASE_K
 * @brief Символ строчной буквы k (ASCII 0x6B).
 */
#define AE_ASCII_MAP_LOWERCASE_K 'k'

/**
 * @def AE_ASCII_MAP_LOWERCASE_L
 * @brief Символ строчной буквы l (ASCII 0x6C).
 */
#define AE_ASCII_MAP_LOWERCASE_L 'l'

/**
 * @def AE_ASCII_MAP_LOWERCASE_M
 * @brief Символ строчной буквы m (ASCII 0x6D).
 */
#define AE_ASCII_MAP_LOWERCASE_M 'm'

/**
 * @def AE_ASCII_MAP_LOWERCASE_N
 * @brief Символ 'n' (нижний регистр).
 *
 * Символ 'n' соответствует коду ASCII 110.
 */
#define AE_ASCII_MAP_LOWERCASE_N 'n'

/**
 * @def AE_ASCII_MAP_LOWERCASE_O
 * @brief Символ 'o' (нижний регистр).
 *
 * Символ 'o' соответствует коду ASCII 111.
 */
#define AE_ASCII_MAP_LOWERCASE_O 'o'

/**
 * @def AE_ASCII_MAP_LOWERCASE_P
 * @brief Символ 'p' (нижний регистр).
 *
 * Символ 'p' соответствует коду ASCII 112.
 */
#define AE_ASCII_MAP_LOWERCASE_P 'p'

/**
 * @def AE_ASCII_MAP_LOWERCASE_Q
 * @brief Символ 'q' (нижний регистр).
 *
 * Символ 'q' соответствует коду ASCII 113.
 */
#define AE_ASCII_MAP_LOWERCASE_Q 'q'

/**
 * @def AE_ASCII_MAP_LOWERCASE_R
 * @brief Символ 'r' (нижний регистр).
 *
 * Символ 'r' соответствует коду ASCII 114.
 */
#define AE_ASCII_MAP_LOWERCASE_R 'r'

/**
 * @def AE_ASCII_MAP_LOWERCASE_S
 * @brief Символ 's' (нижний регистр).
 *
 * Символ 's' соответствует коду ASCII 115.
 */
#define AE_ASCII_MAP_LOWERCASE_S 's'

/**
 * @def AE_ASCII_MAP_LOWERCASE_T
 * @brief Символ 't' (нижний регистр).
 *
 * Символ 't' соответствует коду ASCII 116.
 */
#define AE_ASCII_MAP_LOWERCASE_T 't'

/**
 * @def AE_ASCII_MAP_LOWERCASE_U
 * @brief Символ 'u' (нижний регистр).
 *
 * Символ 'u' соответствует коду ASCII 117.
 */
#define AE_ASCII_MAP_LOWERCASE_U 'u'

/**
 * @def AE_ASCII_MAP_LOWERCASE_V
 * @brief Символ 'v' (нижний регистр).
 *
 * Символ 'v' соответствует коду ASCII 118.
 */
#define AE_ASCII_MAP_LOWERCASE_V 'v'

/**
 * @def AE_ASCII_MAP_LOWERCASE_W
 * @brief Символ 'w' (нижний регистр).
 *
 * Символ 'w' соответствует коду ASCII 119.
 */
#define AE_ASCII_MAP_LOWERCASE_W 'w'

/**
 * @def AE_ASCII_MAP_LOWERCASE_X
 * @brief Символ 'x' (нижний регистр).
 *
 * Символ 'x' соответствует коду ASCII 120.
 */
#define AE_ASCII_MAP_LOWERCASE_X 'x'

/**
 * @def AE_ASCII_MAP_LOWERCASE_Y
 * @brief Символ 'y' (нижний регистр).
 *
 * Символ 'y' соответствует коду ASCII 121.
 */
#define AE_ASCII_MAP_LOWERCASE_Y 'y'

/**
 * @def AE_ASCII_MAP_LOWERCASE_Z
 * @brief Символ 'z' (нижний регистр).
 *
 * Символ 'z' соответствует коду ASCII 122.
 */
#define AE_ASCII_MAP_LOWERCASE_Z 'z'

/**
 * @def AE_ASCII_MAP_LEFT_BRACE
 * @brief Символ '{' (левая фигурная скобка).
 *
 * Символ '{' соответствует коду ASCII 123.
 */
#define AE_ASCII_MAP_LEFT_BRACE '{'

/**
 * @def AE_ASCII_MAP_VERTICAL_BAR
 * @brief Символ '|' (вертикальная черта).
 *
 * Символ '|' соответствует коду ASCII 124.
 */
#define AE_ASCII_MAP_VERTICAL_BAR '|'

/**
 * @def AE_ASCII_MAP_RIGHT_BRACE
 * @brief Символ '}' (правая фигурная скобка).
 */
#define AE_ASCII_MAP_RIGHT_BRACE '}'

/**
 * @def AE_ASCII_MAP_TILDE
 * @brief Символ '~' (тильда).
 */
#define AE_ASCII_MAP_TILDE '~'

/**
 * @def AE_ASCII_MAP_DELETE
 * @brief Символ 'delete' (удаление).
 */
#define AE_ASCII_MAP_DELETE '\x7F'

#endif // AE_ASCII_MAP_H
