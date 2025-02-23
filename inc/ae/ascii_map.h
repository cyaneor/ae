/**
 * @file ascii_map.h
 * @brief Заголовочный файл, содержащий массив символов ASCII.
 *
 * Этот файл определяет массив `AE_ASCII_MAP`, который представляет собой отображение символов
 * ASCII с индексами от 0 до 127. Каждый элемент массива соответствует одному из символов ASCII
 * или управляющему символу.
 *
 * @note Управляющие символы, такие как возврат каретки или сигнал,
 *       представлены в виде соответствующих кодов ASCII.
 */

#ifndef AE_ASCII_MAP_H
#define AE_ASCII_MAP_H

#include "char.h"

/**
 * @brief Массив, отображающий символы ASCII.
 *
 * Этот массив используется для представления символов ASCII с индексами от 0 до 127.
 * Каждый элемент массива соответствует одному из символов ASCII или управляющему символу.
 *
 * @note Управляющие символы, такие как возврат каретки или сигнал, представлены в виде
 *       соответствующих кодов ASCII.
 *
 * @see https://en.wikipedia.org/wiki/ASCII
 */
static const ae_char_t AE_ASCII_MAP[] = {
    [0] = '\0',   /**< @brief Символ нулевого терминатора (NULL) */
    [1] = '\x01', /**< @brief Управляющий символ 1 (CONTROL_1) */
    [2] = '\x02', /**< @brief Управляющий символ 2 (CONTROL_2) */
    [3] = '\x03', /**< @brief Управляющий символ 3 (CONTROL_3) */
    [4] = '\x04', /**< @brief Управляющий символ 4 (CONTROL_4) */
    [5] = '\x05', /**< @brief Управляющий символ 5 (CONTROL_5) */
    [6] = '\x06', /**< @brief Управляющий символ 6 (CONTROL_6) */
    [7] = '\x07', /**< @brief Символ звукового сигнала (BELL) */
    [8] = '\x08', /**< @brief Символ возврата на один символ назад (BACKSPACE) */
    [9]  = '\t', /**< @brief Символ табуляции (TAB) */
    [10] = '\n', /**< @brief Символ новой строки (NEWLINE) */
    [11] = '\x0B', /**< @brief Символ вертикальной табуляции (VERTICAL_TAB) */
    [12] = '\x0C', /**< @brief Символ перевода страницы (FORM_FEED) */
    [13] = '\r',   /**< @brief Символ возврата каретки (CARRIAGE_RETURN) */
    [14] = '\x0E', /**< @brief Символ SHIFT OUT (SHIFT_OUT) */
    [15] = '\x0F', /**< @brief Символ SHIFT IN (SHIFT_IN) */
    [16] = '\x10', /**< @brief Символ Data Link Escape (DATA_LINK_ESCAPE) */
    [17] = '\x11', /**< @brief Символ устройства управления 1 (DEVICE_CONTROL_1) */
    [18] = '\x12', /**< @brief Символ устройства управления 2 (DEVICE_CONTROL_2) */
    [19] = '\x13', /**< @brief Символ устройства управления 3 (DEVICE_CONTROL_3) */
    [20] = '\x14', /**< @brief Символ устройства управления 4 (DEVICE_CONTROL_4) */
    [21] = '\x15', /**< @brief Символ отрицательного подтверждения (NEGATIVE_ACKNOWLEDGE) */
    [22] = '\x16', /**< @brief Символ синхронного бездействия (SYNCHRONOUS_IDLE) */
    [23] = '\x17', /**< @brief Символ конца блока передачи (END_OF_TRANSMISSION_BLOCK) */
    [24] = '\x18', /**< @brief Символ отмены (CANCEL) */
    [25] = '\x19', /**< @brief Символ конца носителя (END_OF_MEDIUM) */
    [26] = '\x1A', /**< @brief Символ замены (SUBSTITUTE) */
    [27] = '\x1B', /**< @brief Символ эскейпа (ESCAPE) */
    [28] = '\x1C', /**< @brief Символ разделителя файла (FILE_SEPARATOR) */
    [29] = '\x1D', /**< @brief Символ разделителя группы (GROUP_SEPARATOR) */
    [30] = '\x1E', /**< @brief Символ разделителя записи (RECORD_SEPARATOR) */
    [31] = '\x1F', /**< @brief Символ разделителя единицы (UNIT_SEPARATOR) */
    [32] = ' ',    /**< @brief Символ пробела (SPACE) */
    [33] = '!',    /**< @brief Символ восклицания (EXCLAMATION_MARK) */
    [34] = '"',    /**< @brief Символ кавычек (QUOTE) */
    [35] = '#',    /**< @brief Символ решетки (HASH) */
    [36] = '$',    /**< @brief Символ доллара (DOLLAR) */
    [37] = '%',    /**< @brief Символ процента (PERCENT) */
    [38] = '&',    /**< @brief Символ амперсанда (AMPERSAND) */
    [39] = '\'',   /**< @brief Символ одинарной кавычки (SINGLE_QUOTE) */
    [40] = '(',    /**< @brief Символ левой скобки (LEFT_PARENTHESIS) */
    [41] = ')',    /**< @brief Символ правой скобки (RIGHT_PARENTHESIS) */
    [42] = '*',    /**< @brief Символ звездочки (ASTERISK) */
    [43] = '+',    /**< @brief Символ плюса (PLUS) */
    [44] = ',',    /**< @brief Символ запятой (COMMA) */
    [45] = '-',    /**< @brief Символ дефиса (HYPHEN) */
    [46] = '.',    /**< @brief Символ точки (PERIOD) */
    [47] = '/',    /**< @brief Символ слэша (SLASH) */
    [48] = '0',    /**< @brief Символ цифры 0 (DIGIT_0) */
    [49] = '1',    /**< @brief Символ цифры 1 (DIGIT_1) */
    [50] = '2',    /**< @brief Символ цифры 2 (DIGIT_2) */
    [51] = '3',    /**< @brief Символ цифры 3 (DIGIT_3) */
    [52] = '4',    /**< @brief Символ цифры 4 (DIGIT_4) */
    [53] = '5',    /**< @brief Символ цифры 5 (DIGIT_5) */
    [54] = '6',    /**< @brief Символ цифры 6 (DIGIT_6) */
    [55] = '7',    /**< @brief Символ цифры 7 (DIGIT_7) */
    [56] = '8',    /**< @brief Символ цифры 8 (DIGIT_8) */
    [57] = '9',    /**< @brief Символ цифры 9 (DIGIT_9) */
    [58] = ':',    /**< @brief Символ двоеточия (COLON) */
    [59] = ';',    /**< @brief Символ точки с запятой (SEMICOLON) */
    [60] = '<',    /**< @brief Символ меньше чем (LESS_THAN) */
    [61] = '=',    /**< @brief Символ равно (EQUAL) */
    [62] = '>',    /**< @brief Символ больше чем (GREATER_THAN) */
    [63] = '?', /**< @brief Символ вопросительного знака (QUESTION_MARK) */
    [64] = '@', /**< @brief Символ собаки (AT) */
    [65] = 'A', /**< @brief Символ заглавной буквы A (UPPERCASE_A) */
    [66] = 'B', /**< @brief Символ заглавной буквы B (UPPERCASE_B) */
    [67] = 'C', /**< @brief Символ заглавной буквы C (UPPERCASE_C) */
    [68] = 'D', /**< @brief Символ заглавной буквы D (UPPERCASE_D) */
    [69] = 'E', /**< @brief Символ заглавной буквы E (UPPERCASE_E) */
    [70] = 'F', /**< @brief Символ заглавной буквы F (UPPERCASE_F) */
    [71] = 'G', /**< @brief Символ заглавной буквы G (UPPERCASE_G) */
    [72] = 'H', /**< @brief Символ заглавной буквы H (UPPERCASE_H) */
    [73] = 'I', /**< @brief Символ заглавной буквы I (UPPERCASE_I) */
    [74] = 'J', /**< @brief Символ заглавной буквы J (UPPERCASE_J) */
    [75] = 'K', /**< @brief Символ заглавной буквы K (UPPERCASE_K) */
    [76] = 'L', /**< @brief Символ заглавной буквы L (UPPERCASE_L) */
    [77] = 'M', /**< @brief Символ заглавной буквы M (UPPERCASE_M) */
    [78] = 'N', /**< @brief Символ заглавной буквы N (UPPERCASE_N) */
    [79] = 'O', /**< @brief Символ заглавной буквы O (UPPERCASE_O) */
    [80] = 'P', /**< @brief Символ заглавной буквы P (UPPERCASE_P) */
    [81] = 'Q', /**< @brief Символ заглавной буквы Q (UPPERCASE_Q) */
    [82] = 'R', /**< @brief Символ заглавной буквы R (UPPERCASE_R) */
    [83] = 'S', /**< @brief Символ заглавной буквы S (UPPERCASE_S) */
    [84] = 'T', /**< @brief Символ заглавной буквы T (UPPERCASE_T) */
    [85] = 'U', /**< @brief Символ заглавной буквы U (UPPERCASE_U) */
    [86] = 'V', /**< @brief Символ заглавной буквы V (UPPERCASE_V) */
    [87] = 'W', /**< @brief Символ заглавной буквы W (UPPERCASE_W) */
    [88] = 'X', /**< @brief Символ заглавной буквы X (UPPERCASE_X) */
    [89] = 'Y', /**< @brief Символ заглавной буквы Y (UPPERCASE_Y) */
    [90] = 'Z', /**< @brief Символ заглавной буквы Z (UPPERCASE_Z) */
    [91] = '[', /**< @brief Символ левой квадратной скобки (LEFT_BRACKET) */
    [92] = '\\', /**< @brief Символ обратной косой черты (BACKSLASH) */
    [93] = ']', /**< @brief Символ правой квадратной скобки (RIGHT_BRACKET) */
    [94]  = '^', /**< @brief Символ циркумфлекса (CIRCUMFLEX_ACCENT) */
    [95]  = '_', /**< @brief Символ подчеркивания (UNDERSCORE) */
    [96]  = '`', /**< @brief Символ обратной кавычки (GRAVE_ACCENT) */
    [97]  = 'a', /**< @brief Символ строчной буквы a (LOWERCASE_A) */
    [98]  = 'b', /**< @brief Символ строчной буквы b (LOWERCASE_B) */
    [99]  = 'c', /**< @brief Символ строчной буквы c (LOWERCASE_C) */
    [100] = 'd', /**< @brief Символ строчной буквы d (LOWERCASE_D) */
    [101] = 'e', /**< @brief Символ строчной буквы e (LOWERCASE_E) */
    [102] = 'f', /**< @brief Символ строчной буквы f (LOWERCASE_F) */
    [103] = 'g', /**< @brief Символ строчной буквы g (LOWERCASE_G) */
    [104] = 'h', /**< @brief Символ строчной буквы h (LOWERCASE_H) */
    [105] = 'i', /**< @brief Символ строчной буквы i (LOWERCASE_I) */
    [106] = 'j', /**< @brief Символ строчной буквы j (LOWERCASE_J) */
    [107] = 'k', /**< @brief Символ строчной буквы k (LOWERCASE_K) */
    [108] = 'l', /**< @brief Символ строчной буквы l (LOWERCASE_L) */
    [109] = 'm', /**< @brief Символ строчной буквы m (LOWERCASE_M) */
    [110] = 'n', /**< @brief Символ строчной буквы n (LOWERCASE_N) */
    [111] = 'o', /**< @brief Символ строчной буквы o (LOWERCASE_O) */
    [112] = 'p', /**< @brief Символ строчной буквы p (LOWERCASE_P) */
    [113] = 'q', /**< @brief Символ строчной буквы q (LOWERCASE_Q) */
    [114] = 'r', /**< @brief Символ строчной буквы r (LOWERCASE_R) */
    [115] = 's', /**< @brief Символ строчной буквы s (LOWERCASE_S) */
    [116] = 't', /**< @brief Символ строчной буквы t (LOWERCASE_T) */
    [117] = 'u', /**< @brief Символ строчной буквы u (LOWERCASE_U) */
    [118] = 'v', /**< @brief Символ строчной буквы v (LOWERCASE_V) */
    [119] = 'w', /**< @brief Символ строчной буквы w (LOWERCASE_W) */
    [120] = 'x', /**< @brief Символ строчной буквы x (LOWERCASE_X) */
    [121] = 'y', /**< @brief Символ строчной буквы y (LOWERCASE_Y) */
    [122] = 'z', /**< @brief Символ строчной буквы z (LOWERCASE_Z) */
    [123] = '{', /**< @brief Символ левой фигурной скобки (LEFT_BRACE) */
    [124] = '|', /**< @brief Символ вертикальной черты (VERTICAL_BAR) */
    [125] = '}', /**< @brief Символ правой фигурной скобки (RIGHT_BRACE) */
    [126] = '~',   /**< @brief Символ тильды (TILDE) */
    [127] = '\x7F' /**< @brief Символ удаления (DELETE) */
};

/**
 * @def AE_ASCII_MAP_NULL_TERMINATOR
 * @brief Символ завершения строки (NULL).
 */
#define AE_ASCII_MAP_NULL_TERMINATOR AE_ASCII_MAP[0]

/**
 * @def AE_ASCII_MAP_CONTROL_1
 * @brief Управляющий символ 1 (ASCII 0x01).
 */
#define AE_ASCII_MAP_CONTROL_1 AE_ASCII_MAP[1]

/**
 * @def AE_ASCII_MAP_CONTROL_2
 * @brief Управляющий символ 2 (ASCII 0x02).
 */
#define AE_ASCII_MAP_CONTROL_2 AE_ASCII_MAP[2]

/**
 * @def AE_ASCII_MAP_CONTROL_3
 * @brief Управляющий символ 3 (ASCII 0x03).
 */
#define AE_ASCII_MAP_CONTROL_3 AE_ASCII_MAP[3]

/**
 * @def AE_ASCII_MAP_CONTROL_4
 * @brief Управляющий символ 4 (ASCII 0x04).
 */
#define AE_ASCII_MAP_CONTROL_4 AE_ASCII_MAP[4]

/**
 * @def AE_ASCII_MAP_CONTROL_5
 * @brief Управляющий символ 5 (ASCII 0x05).
 */
#define AE_ASCII_MAP_CONTROL_5 AE_ASCII_MAP[5]

/**
 * @def AE_ASCII_MAP_CONTROL_6
 * @brief Управляющий символ 6 (ASCII 0x06).
 */
#define AE_ASCII_MAP_CONTROL_6 AE_ASCII_MAP[6]

/**
 * @def AE_ASCII_MAP_BELL
 * @brief Символ "звонок" (ASCII 0x07).
 */
#define AE_ASCII_MAP_BELL AE_ASCII_MAP[7]

/**
 * @def AE_ASCII_MAP_BACKSPACE
 * @brief Символ "удаление" (ASCII 0x08).
 */
#define AE_ASCII_MAP_BACKSPACE AE_ASCII_MAP[8]

/**
 * @def AE_ASCII_MAP_TAB_SYMBOL
 * @brief Символ табуляции (ASCII 0x09).
 */
#define AE_ASCII_MAP_TAB_SYMBOL AE_ASCII_MAP[9]

/**
 * @def AE_ASCII_MAP_NEWLINE_SYMBOL
 * @brief Символ новой строки (ASCII 0x0A).
 */
#define AE_ASCII_MAP_NEWLINE_SYMBOL AE_ASCII_MAP[10]

/**
 * @def AE_ASCII_MAP_VERTICAL_TAB
 * @brief Символ вертикальной табуляции (ASCII 0x0B).
 */
#define AE_ASCII_MAP_VERTICAL_TAB AE_ASCII_MAP[11]

/**
 * @def AE_ASCII_MAP_FORM_FEED
 * @brief Символ перевода страницы (ASCII 0x0C).
 */
#define AE_ASCII_MAP_FORM_FEED AE_ASCII_MAP[12]

/**
 * @def AE_ASCII_MAP_CARRIAGE_RETURN_SYMBOL
 * @brief Символ возврата каретки (ASCII 0x0D).
 */
#define AE_ASCII_MAP_CARRIAGE_RETURN_SYMBOL AE_ASCII_MAP[13]

/**
 * @def AE_ASCII_MAP_SHIFT_OUT
 * @brief Символ "выход из сдвига" (ASCII 0x0E).
 */
#define AE_ASCII_MAP_SHIFT_OUT AE_ASCII_MAP[14]

/**
 * @def AE_ASCII_MAP_SHIFT_IN
 * @brief Символ "вход в сдвиг" (ASCII 0x0F).
 */
#define AE_ASCII_MAP_SHIFT_IN AE_ASCII_MAP[15]

/**
 * @def AE_ASCII_MAP_DATA_LINK_ESCAPE
 * @brief Символ "ссылка на данные" (ASCII 0x10).
 */
#define AE_ASCII_MAP_DATA_LINK_ESCAPE AE_ASCII_MAP[16]

/**
 * @def AE_ASCII_MAP_DEVICE_CONTROL_1
 * @brief Управляющий символ 1 для устройства (ASCII 0x11).
 */
#define AE_ASCII_MAP_DEVICE_CONTROL_1 AE_ASCII_MAP[17]

/**
 * @def AE_ASCII_MAP_DEVICE_CONTROL_2
 * @brief Управляющий символ 2 для устройства (ASCII 0x12).
 */
#define AE_ASCII_MAP_DEVICE_CONTROL_2 AE_ASCII_MAP[18]

/**
 * @def AE_ASCII_MAP_DEVICE_CONTROL_3
 * @brief Управляющий символ 3 для устройства (ASCII 0x13).
 */
#define AE_ASCII_MAP_DEVICE_CONTROL_3 AE_ASCII_MAP[19]

/**
 * @def AE_ASCII_MAP_DEVICE_CONTROL_4
 * @brief Управляющий символ 4 для устройства (ASCII 0x14).
 */
#define AE_ASCII_MAP_DEVICE_CONTROL_4 AE_ASCII_MAP[20]

/**
 * @def AE_ASCII_MAP_NEGATIVE_ACKNOWLEDGE
 * @brief Символ отрицательного подтверждения (ASCII 0x15).
 */
#define AE_ASCII_MAP_NEGATIVE_ACKNOWLEDGE AE_ASCII_MAP[21]

/**
 * @def AE_ASCII_MAP_SYNCHRONOUS_IDLE
 * @brief Символ синхронного простоя (ASCII 0x16).
 */
#define AE_ASCII_MAP_SYNCHRONOUS_IDLE AE_ASCII_MAP[22]

/**
 * @def AE_ASCII_MAP_END_OF_TRANSMISSION_BLOCK
 * @brief Символ конца блока передачи (ASCII 0x17).
 */
#define AE_ASCII_MAP_END_OF_TRANSMISSION_BLOCK AE_ASCII_MAP[23]

/**
 * @def AE_ASCII_MAP_CANCEL
 * @brief Символ отмены (ASCII 0x18).
 */
#define AE_ASCII_MAP_CANCEL AE_ASCII_MAP[24]

/**
 * @def AE_ASCII_MAP_END_OF_MEDIUM
 * @brief Символ конца носителя (ASCII 0x19).
 */
#define AE_ASCII_MAP_END_OF_MEDIUM AE_ASCII_MAP[25]

/**
 * @def AE_ASCII_MAP_SUBSTITUTE
 * @brief Символ замены (ASCII 0x1A).
 */
#define AE_ASCII_MAP_SUBSTITUTE AE_ASCII_MAP[26]

/**
 * @def AE_ASCII_MAP_ESCAPE
 * @brief Символ экранирования (ASCII 0x1B).
 */
#define AE_ASCII_MAP_ESCAPE AE_ASCII_MAP[27]

/**
 * @def AE_ASCII_MAP_FILE_SEPARATOR
 * @brief Символ разделителя файлов (ASCII 0x1C).
 */
#define AE_ASCII_MAP_FILE_SEPARATOR AE_ASCII_MAP[28]

/**
 * @def AE_ASCII_MAP_GROUP_SEPARATOR
 * @brief Символ разделителя групп (ASCII 0x1D).
 */
#define AE_ASCII_MAP_GROUP_SEPARATOR AE_ASCII_MAP[29]

/**
 * @def AE_ASCII_MAP_RECORD_SEPARATOR
 * @brief Символ разделителя записей (ASCII 0x1E).
 */
#define AE_ASCII_MAP_RECORD_SEPARATOR AE_ASCII_MAP[30]

/**
 * @def AE_ASCII_MAP_UNIT_SEPARATOR
 * @brief Символ разделителя единиц (ASCII 0x1F).
 */
#define AE_ASCII_MAP_UNIT_SEPARATOR AE_ASCII_MAP[31]

/**
 * @def AE_ASCII_MAP_SPACE_SYMBOL
 * @brief Символ пробела (ASCII 0x20).
 */
#define AE_ASCII_MAP_SPACE_SYMBOL AE_ASCII_MAP[32]

/**
 * @def AE_ASCII_MAP_EXCLAMATION_MARK_SYMBOL
 * @brief Символ восклицательного знака (ASCII 0x21).
 */
#define AE_ASCII_MAP_EXCLAMATION_MARK_SYMBOL AE_ASCII_MAP[33]

/**
 * @def AE_ASCII_MAP_QUOTE_SYMBOL
 * @brief Символ кавычки (ASCII 0x22).
 */
#define AE_ASCII_MAP_QUOTE_SYMBOL AE_ASCII_MAP[34]

/**
 * @def AE_ASCII_MAP_HASH_SYMBOL
 * @brief Символ решетки (ASCII 0x23).
 */
#define AE_ASCII_MAP_HASH_SYMBOL AE_ASCII_MAP[35]

/**
 * @def AE_ASCII_MAP_DOLLAR_SYMBOL
 * @brief Символ доллара (ASCII 0x24).
 */
#define AE_ASCII_MAP_DOLLAR_SYMBOL AE_ASCII_MAP[36]

/**
 * @def AE_ASCII_MAP_PERCENT_SYMBOL
 * @brief Символ процента (ASCII 0x25).
 */
#define AE_ASCII_MAP_PERCENT_SYMBOL AE_ASCII_MAP[37]

/**
 * @def AE_ASCII_MAP_AMPERSAND_SYMBOL
 * @brief Символ амперсанда (ASCII 0x26).
 */
#define AE_ASCII_MAP_AMPERSAND_SYMBOL AE_ASCII_MAP[38]

/**
 * @def AE_ASCII_MAP_SINGLE_QUOTE_SYMBOL
 * @brief Символ одинарной кавычки (ASCII 0x27).
 */
#define AE_ASCII_MAP_SINGLE_QUOTE_SYMBOL AE_ASCII_MAP[39]

/**
 * @def AE_ASCII_MAP_LEFT_PARENTHESIS
 * @brief Символ левой скобки (ASCII 0x28).
 */
#define AE_ASCII_MAP_LEFT_PARENTHESIS AE_ASCII_MAP[40]

/**
 * @def AE_ASCII_MAP_RIGHT_PARENTHESIS
 * @brief Символ правой скобки (ASCII 0x29).
 */
#define AE_ASCII_MAP_RIGHT_PARENTHESIS AE_ASCII_MAP[41]

/**
 * @def AE_ASCII_MAP_ASTERISK_SYMBOL
 * @brief Символ звездочки (ASCII 0x2A).
 */
#define AE_ASCII_MAP_ASTERISK_SYMBOL AE_ASCII_MAP[42]

/**
 * @def AE_ASCII_MAP_PLUS_SYMBOL
 * @brief Символ плюса (ASCII 0x2B).
 */
#define AE_ASCII_MAP_PLUS_SYMBOL AE_ASCII_MAP[43]

/**
 * @def AE_ASCII_MAP_COMMA_SYMBOL
 * @brief Символ запятой (ASCII 0x2C).
 */
#define AE_ASCII_MAP_COMMA_SYMBOL AE_ASCII_MAP[44]

/**
 * @def AE_ASCII_MAP_HYPHEN_SYMBOL
 * @brief Символ дефиса (ASCII 0x2D).
 */
#define AE_ASCII_MAP_HYPHEN_SYMBOL AE_ASCII_MAP[45]

/**
 * @def AE_ASCII_MAP_PERIOD_SYMBOL
 * @brief Символ точки (ASCII 0x2E).
 */
#define AE_ASCII_MAP_PERIOD_SYMBOL AE_ASCII_MAP[46]

/**
 * @def AE_ASCII_MAP_SLASH_SYMBOL
 * @brief Символ косой черты (ASCII 0x2F).
 */
#define AE_ASCII_MAP_SLASH_SYMBOL AE_ASCII_MAP[47]

/**
 * @def AE_ASCII_MAP_DIGIT_0
 * @brief Символ цифры 0 (ASCII 0x30).
 */
#define AE_ASCII_MAP_DIGIT_0 AE_ASCII_MAP[48]

/**
 * @def AE_ASCII_MAP_DIGIT_1
 * @brief Символ цифры 1 (ASCII 0x31).
 */
#define AE_ASCII_MAP_DIGIT_1 AE_ASCII_MAP[49]

/**
 * @def AE_ASCII_MAP_DIGIT_2
 * @brief Символ цифры 2 (ASCII 0x32).
 */
#define AE_ASCII_MAP_DIGIT_2 AE_ASCII_MAP[50]

/**
 * @def AE_ASCII_MAP_DIGIT_3
 * @brief Символ цифры 3 (ASCII 0x33).
 */
#define AE_ASCII_MAP_DIGIT_3 AE_ASCII_MAP[51]

/**
 * @def AE_ASCII_MAP_DIGIT_4
 * @brief Символ цифры 4 (ASCII 0x34).
 */
#define AE_ASCII_MAP_DIGIT_4 AE_ASCII_MAP[52]

/**
 * @def AE_ASCII_MAP_DIGIT_5
 * @brief Символ цифры 5 (ASCII 0x35).
 */
#define AE_ASCII_MAP_DIGIT_5 AE_ASCII_MAP[53]

/**
 * @def AE_ASCII_MAP_DIGIT_6
 * @brief Символ цифры 6 (ASCII 0x36).
 */
#define AE_ASCII_MAP_DIGIT_6 AE_ASCII_MAP[54]

/**
 * @def AE_ASCII_MAP_DIGIT_7
 * @brief Символ цифры 7 (ASCII 0x37).
 */
#define AE_ASCII_MAP_DIGIT_7 AE_ASCII_MAP[55]

/**
 * @def AE_ASCII_MAP_DIGIT_8
 * @brief Символ цифры 8 (ASCII 0x38).
 */
#define AE_ASCII_MAP_DIGIT_8 AE_ASCII_MAP[56]

/**
 * @def AE_ASCII_MAP_DIGIT_9
 * @brief Символ цифры 9 (ASCII 0x39).
 */
#define AE_ASCII_MAP_DIGIT_9 AE_ASCII_MAP[57]

/**
 * @def AE_ASCII_MAP_COLON_SYMBOL
 * @brief Символ двоеточия (ASCII 0x3A).
 */
#define AE_ASCII_MAP_COLON_SYMBOL AE_ASCII_MAP[58]

/**
 * @def AE_ASCII_MAP_SEMICOLON_SYMBOL
 * @brief Символ точки с запятой (ASCII 0x3B).
 */
#define AE_ASCII_MAP_SEMICOLON_SYMBOL AE_ASCII_MAP[59]

/**
 * @def AE_ASCII_MAP_LESS_THAN_SYMBOL
 * @brief Символ меньше (ASCII 0x3C).
 */
#define AE_ASCII_MAP_LESS_THAN_SYMBOL AE_ASCII_MAP[60]

/**
 * @def AE_ASCII_MAP_EQUAL_SYMBOL
 * @brief Символ равенства (ASCII 0x3D).
 */
#define AE_ASCII_MAP_EQUAL_SYMBOL AE_ASCII_MAP[61]

/**
 * @def AE_ASCII_MAP_GREATER_THAN_SYMBOL
 * @brief Символ больше (ASCII 0x3E).
 */
#define AE_ASCII_MAP_GREATER_THAN_SYMBOL AE_ASCII_MAP[62]

/**
 * @def AE_ASCII_MAP_QUESTION_MARK_SYMBOL
 * @brief Символ вопросительного знака (ASCII 0x3F).
 */
#define AE_ASCII_MAP_QUESTION_MARK_SYMBOL AE_ASCII_MAP[63]

/**
 * @def AE_ASCII_MAP_AT_SYMBOL
 * @brief Символ собачки (ASCII 0x40).
 */
#define AE_ASCII_MAP_AT_SYMBOL AE_ASCII_MAP[64]

/**
 * @def AE_ASCII_MAP_UPPERCASE_A
 * @brief Символ заглавной буквы A (ASCII 0x41).
 */
#define AE_ASCII_MAP_UPPERCASE_A AE_ASCII_MAP[65]

/**
 * @def AE_ASCII_MAP_UPPERCASE_B
 * @brief Символ заглавной буквы B (ASCII 0x42).
 */
#define AE_ASCII_MAP_UPPERCASE_B AE_ASCII_MAP[66]

/**
 * @def AE_ASCII_MAP_UPPERCASE_C
 * @brief Символ заглавной буквы C (ASCII 0x43).
 */
#define AE_ASCII_MAP_UPPERCASE_C AE_ASCII_MAP[67]

/**
 * @def AE_ASCII_MAP_UPPERCASE_D
 * @brief Символ заглавной буквы D (ASCII 0x44).
 */
#define AE_ASCII_MAP_UPPERCASE_D AE_ASCII_MAP[68]

/**
 * @def AE_ASCII_MAP_UPPERCASE_E
 * @brief Символ заглавной буквы E (ASCII 0x45).
 */
#define AE_ASCII_MAP_UPPERCASE_E AE_ASCII_MAP[69]

/**
 * @def AE_ASCII_MAP_UPPERCASE_F
 * @brief Символ заглавной буквы F (ASCII 0x46).
 */
#define AE_ASCII_MAP_UPPERCASE_F AE_ASCII_MAP[70]

/**
 * @def AE_ASCII_MAP_UPPERCASE_G
 * @brief Символ заглавной буквы G (ASCII 0x47).
 */
#define AE_ASCII_MAP_UPPERCASE_G AE_ASCII_MAP[71]

/**
 * @def AE_ASCII_MAP_UPPERCASE_H
 * @brief Символ заглавной буквы H (ASCII 0x48).
 */
#define AE_ASCII_MAP_UPPERCASE_H AE_ASCII_MAP[72]

/**
 * @def AE_ASCII_MAP_UPPERCASE_I
 * @brief Символ заглавной буквы I (ASCII 0x49).
 */
#define AE_ASCII_MAP_UPPERCASE_I AE_ASCII_MAP[73]

/**
 * @def AE_ASCII_MAP_UPPERCASE_J
 * @brief Символ заглавной буквы J (ASCII 0x4A).
 */
#define AE_ASCII_MAP_UPPERCASE_J AE_ASCII_MAP[74]

/**
 * @def AE_ASCII_MAP_UPPERCASE_K
 * @brief Символ заглавной буквы K (ASCII 0x4B).
 */
#define AE_ASCII_MAP_UPPERCASE_K AE_ASCII_MAP[75]

/**
 * @def AE_ASCII_MAP_UPPERCASE_L
 * @brief Символ заглавной буквы L (ASCII 0x4C).
 */
#define AE_ASCII_MAP_UPPERCASE_L AE_ASCII_MAP[76]

/**
 * @def AE_ASCII_MAP_UPPERCASE_M
 * @brief Символ заглавной буквы M (ASCII 0x4D).
 */
#define AE_ASCII_MAP_UPPERCASE_M AE_ASCII_MAP[77]

/**
 * @def AE_ASCII_MAP_UPPERCASE_N
 * @brief Символ заглавной буквы N (ASCII 0x4E).
 */
#define AE_ASCII_MAP_UPPERCASE_N AE_ASCII_MAP[78]

/**
 * @def AE_ASCII_MAP_UPPERCASE_O
 * @brief Символ заглавной буквы O (ASCII 0x4F).
 */
#define AE_ASCII_MAP_UPPERCASE_O AE_ASCII_MAP[79]

/**
 * @def AE_ASCII_MAP_UPPERCASE_P
 * @brief Символ заглавной буквы P (ASCII 0x50).
 */
#define AE_ASCII_MAP_UPPERCASE_P AE_ASCII_MAP[80]

/**
 * @def AE_ASCII_MAP_UPPERCASE_Q
 * @brief Символ заглавной буквы Q (ASCII 0x51).
 */
#define AE_ASCII_MAP_UPPERCASE_Q AE_ASCII_MAP[81]

/**
 * @def AE_ASCII_MAP_UPPERCASE_R
 * @brief Символ заглавной буквы R (ASCII 0x52).
 */
#define AE_ASCII_MAP_UPPERCASE_R AE_ASCII_MAP[82]

/**
 * @def AE_ASCII_MAP_UPPERCASE_S
 * @brief Символ заглавной буквы S (ASCII 0x53).
 */
#define AE_ASCII_MAP_UPPERCASE_S AE_ASCII_MAP[83]

/**
 * @def AE_ASCII_MAP_UPPERCASE_T
 * @brief Символ заглавной буквы T (ASCII 0x54).
 */
#define AE_ASCII_MAP_UPPERCASE_T AE_ASCII_MAP[84]

/**
 * @def AE_ASCII_MAP_UPPERCASE_U
 * @brief Символ заглавной буквы U (ASCII 0x55).
 */
#define AE_ASCII_MAP_UPPERCASE_U AE_ASCII_MAP[85]

/**
 * @def AE_ASCII_MAP_UPPERCASE_V
 * @brief Символ заглавной буквы V (ASCII 0x56).
 */
#define AE_ASCII_MAP_UPPERCASE_V AE_ASCII_MAP[86]

/**
 * @def AE_ASCII_MAP_UPPERCASE_W
 * @brief Символ заглавной буквы W (ASCII 0x57).
 */
#define AE_ASCII_MAP_UPPERCASE_W AE_ASCII_MAP[87]

/**
 * @def AE_ASCII_MAP_UPPERCASE_X
 * @brief Символ заглавной буквы X (ASCII 0x58).
 */
#define AE_ASCII_MAP_UPPERCASE_X AE_ASCII_MAP[88]

/**
 * @def AE_ASCII_MAP_UPPERCASE_Y
 * @brief Символ заглавной буквы Y (ASCII 0x59).
 */
#define AE_ASCII_MAP_UPPERCASE_Y AE_ASCII_MAP[89]

/**
 * @def AE_ASCII_MAP_UPPERCASE_Z
 * @brief Символ заглавной буквы Z (ASCII 0x5A).
 */
#define AE_ASCII_MAP_UPPERCASE_Z AE_ASCII_MAP[90]

/**
 * @def AE_ASCII_MAP_LEFT_BRACKET
 * @brief Символ левой квадратной скобки (ASCII 0x5B).
 */
#define AE_ASCII_MAP_LEFT_BRACKET AE_ASCII_MAP[91]

/**
 * @def AE_ASCII_MAP_BACKSLASH
 * @brief Символ обратной косой черты (ASCII 0x5C).
 */
#define AE_ASCII_MAP_BACKSLASH AE_ASCII_MAP[92]

/**
 * @def AE_ASCII_MAP_RIGHT_BRACKET
 * @brief Символ правой квадратной скобки (ASCII 0x5D).
 */
#define AE_ASCII_MAP_RIGHT_BRACKET AE_ASCII_MAP[93]

/**
 * @def AE_ASCII_MAP_CARET_SYMBOL
 * @brief Символ каретки (ASCII 0x5E).
 */
#define AE_ASCII_MAP_CARET_SYMBOL AE_ASCII_MAP[94]

/**
 * @def AE_ASCII_MAP_UNDERLINE_SYMBOL
 * @brief Символ подчеркивания (ASCII 0x5F).
 */
#define AE_ASCII_MAP_UNDERLINE_SYMBOL AE_ASCII_MAP[95]

/**
 * @def AE_ASCII_MAP_GRAVE_SYMBOL
 * @brief Символ грависа (ASCII 0x60).
 */
#define AE_ASCII_MAP_GRAVE_SYMBOL AE_ASCII_MAP[96]

/**
 * @def AE_ASCII_MAP_LOWERCASE_A
 * @brief Символ строчной буквы a (ASCII 0x61).
 */
#define AE_ASCII_MAP_LOWERCASE_A AE_ASCII_MAP[97]

/**
 * @def AE_ASCII_MAP_LOWERCASE_B
 * @brief Символ строчной буквы b (ASCII 0x62).
 */
#define AE_ASCII_MAP_LOWERCASE_B AE_ASCII_MAP[98]

/**
 * @def AE_ASCII_MAP_LOWERCASE_C
 * @brief Символ строчной буквы c (ASCII 0x63).
 */
#define AE_ASCII_MAP_LOWERCASE_C AE_ASCII_MAP[99]

/**
 * @def AE_ASCII_MAP_LOWERCASE_D
 * @brief Символ строчной буквы d (ASCII 0x64).
 */
#define AE_ASCII_MAP_LOWERCASE_D AE_ASCII_MAP[100]

/**
 * @def AE_ASCII_MAP_LOWERCASE_E
 * @brief Символ строчной буквы e (ASCII 0x65).
 */
#define AE_ASCII_MAP_LOWERCASE_E AE_ASCII_MAP[101]

/**
 * @def AE_ASCII_MAP_LOWERCASE_F
 * @brief Символ строчной буквы f (ASCII 0x66).
 */
#define AE_ASCII_MAP_LOWERCASE_F AE_ASCII_MAP[102]

/**
 * @def AE_ASCII_MAP_LOWERCASE_G
 * @brief Символ строчной буквы g (ASCII 0x67).
 */
#define AE_ASCII_MAP_LOWERCASE_G AE_ASCII_MAP[103]

/**
 * @def AE_ASCII_MAP_LOWERCASE_H
 * @brief Символ строчной буквы h (ASCII 0x68).
 */
#define AE_ASCII_MAP_LOWERCASE_H AE_ASCII_MAP[104]

/**
 * @def AE_ASCII_MAP_LOWERCASE_I
 * @brief Символ строчной буквы i (ASCII 0x69).
 */
#define AE_ASCII_MAP_LOWERCASE_I AE_ASCII_MAP[105]

/**
 * @def AE_ASCII_MAP_LOWERCASE_J
 * @brief Символ строчной буквы j (ASCII 0x6A).
 */
#define AE_ASCII_MAP_LOWERCASE_J AE_ASCII_MAP[106]

/**
 * @def AE_ASCII_MAP_LOWERCASE_K
 * @brief Символ строчной буквы k (ASCII 0x6B).
 */
#define AE_ASCII_MAP_LOWERCASE_K AE_ASCII_MAP[107]

/**
 * @def AE_ASCII_MAP_LOWERCASE_L
 * @brief Символ строчной буквы l (ASCII 0x6C).
 */
#define AE_ASCII_MAP_LOWERCASE_L AE_ASCII_MAP[108]

/**
 * @def AE_ASCII_MAP_LOWERCASE_M
 * @brief Символ строчной буквы m (ASCII 0x6D).
 */
#define AE_ASCII_MAP_LOWERCASE_M AE_ASCII_MAP[109]

/**
 * @def AE_ASCII_MAP_LOWERCASE_N
 * @brief Символ 'n' (нижний регистр).
 *
 * Символ 'n' соответствует коду ASCII 110.
 */
#define AE_ASCII_MAP_LOWERCASE_N AE_ASCII_MAP[110]

/**
 * @def AE_ASCII_MAP_LOWERCASE_O
 * @brief Символ 'o' (нижний регистр).
 *
 * Символ 'o' соответствует коду ASCII 111.
 */
#define AE_ASCII_MAP_LOWERCASE_O AE_ASCII_MAP[111]

/**
 * @def AE_ASCII_MAP_LOWERCASE_P
 * @brief Символ 'p' (нижний регистр).
 *
 * Символ 'p' соответствует коду ASCII 112.
 */
#define AE_ASCII_MAP_LOWERCASE_P AE_ASCII_MAP[112]

/**
 * @def AE_ASCII_MAP_LOWERCASE_Q
 * @brief Символ 'q' (нижний регистр).
 *
 * Символ 'q' соответствует коду ASCII 113.
 */
#define AE_ASCII_MAP_LOWERCASE_Q AE_ASCII_MAP[113]

/**
 * @def AE_ASCII_MAP_LOWERCASE_R
 * @brief Символ 'r' (нижний регистр).
 *
 * Символ 'r' соответствует коду ASCII 114.
 */
#define AE_ASCII_MAP_LOWERCASE_R AE_ASCII_MAP[114]

/**
 * @def AE_ASCII_MAP_LOWERCASE_S
 * @brief Символ 's' (нижний регистр).
 *
 * Символ 's' соответствует коду ASCII 115.
 */
#define AE_ASCII_MAP_LOWERCASE_S AE_ASCII_MAP[115]

/**
 * @def AE_ASCII_MAP_LOWERCASE_T
 * @brief Символ 't' (нижний регистр).
 *
 * Символ 't' соответствует коду ASCII 116.
 */
#define AE_ASCII_MAP_LOWERCASE_T AE_ASCII_MAP[116]

/**
 * @def AE_ASCII_MAP_LOWERCASE_U
 * @brief Символ 'u' (нижний регистр).
 *
 * Символ 'u' соответствует коду ASCII 117.
 */
#define AE_ASCII_MAP_LOWERCASE_U AE_ASCII_MAP[117]

/**
 * @def AE_ASCII_MAP_LOWERCASE_V
 * @brief Символ 'v' (нижний регистр).
 *
 * Символ 'v' соответствует коду ASCII 118.
 */
#define AE_ASCII_MAP_LOWERCASE_V AE_ASCII_MAP[118]

/**
 * @def AE_ASCII_MAP_LOWERCASE_W
 * @brief Символ 'w' (нижний регистр).
 *
 * Символ 'w' соответствует коду ASCII 119.
 */
#define AE_ASCII_MAP_LOWERCASE_W AE_ASCII_MAP[119]

/**
 * @def AE_ASCII_MAP_LOWERCASE_X
 * @brief Символ 'x' (нижний регистр).
 *
 * Символ 'x' соответствует коду ASCII 120.
 */
#define AE_ASCII_MAP_LOWERCASE_X AE_ASCII_MAP[120]

/**
 * @def AE_ASCII_MAP_LOWERCASE_Y
 * @brief Символ 'y' (нижний регистр).
 *
 * Символ 'y' соответствует коду ASCII 121.
 */
#define AE_ASCII_MAP_LOWERCASE_Y AE_ASCII_MAP[121]

/**
 * @def AE_ASCII_MAP_LOWERCASE_Z
 * @brief Символ 'z' (нижний регистр).
 *
 * Символ 'z' соответствует коду ASCII 122.
 */
#define AE_ASCII_MAP_LOWERCASE_Z AE_ASCII_MAP[122]

/**
 * @def AE_ASCII_MAP_LEFT_BRACE
 * @brief Символ '{' (левая фигурная скобка).
 *
 * Символ '{' соответствует коду ASCII 123.
 */
#define AE_ASCII_MAP_LEFT_BRACE AE_ASCII_MAP[123]

/**
 * @def AE_ASCII_MAP_VERTICAL_BAR
 * @brief Символ '|' (вертикальная черта).
 *
 * Символ '|' соответствует коду ASCII 124.
 */
#define AE_ASCII_MAP_VERTICAL_BAR AE_ASCII_MAP[124]

/**
 * @def AE_ASCII_MAP_RIGHT_BRACE
 * @brief Символ '}' (правая фигурная скобка).
 */
#define AE_ASCII_MAP_RIGHT_BRACE AE_ASCII_MAP[125]

/**
 * @def AE_ASCII_MAP_TILDE
 * @brief Символ '~' (тильда).
 */
#define AE_ASCII_MAP_TILDE AE_ASCII_MAP[126]

/**
 * @def AE_ASCII_MAP_DELETE
 * @brief Символ 'delete' (удаление).
 */
#define AE_ASCII_MAP_DELETE AE_ASCII_MAP[127]

#endif // AE_ASCII_MAP_H
