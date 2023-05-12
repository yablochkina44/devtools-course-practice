// Copyright 2023 Kudryashov Nikita
#include <gtest/gtest.h>
#include "include/Encoder.h"


TEST(Kudryashov_Nikita_Base64_Encoder_test, Can_encode_letter_string) {
    // Arrange
    string str = "Hello World";
    string expectedStr = "SGVsbG8gV29ybGQ=";

    // Act
    string result = Base64Encoder::strToBase64(str);

    // Assert
    EXPECT_EQ(expectedStr, result);
}

TEST(Kudryashov_Nikita_Base64_Encoder_test, Can_encode_number_string) {
    // Arrange
    string str = "123442463267835123421345125";
    string expectedStr = "MTIzNDQyNDYzMjY3ODM1MTIzNDIxMzQ1MTI1";

    // Act
    string result = Base64Encoder::strToBase64(str);

    // Assert
    EXPECT_EQ(expectedStr, result);
}

TEST(Kudryashov_Nikita_Base64_Encoder_test, Can_encode_symbol_string) {
    // Arrange
    string str = "&+#!-+$_!-&$!$!&@%+@*+=*^-$*+-";
    string expectedStr = "JisjIS0rJF8hLSYkISQhJkAlK0AqKz0qXi0kKist";

    // Act
    string result = Base64Encoder::strToBase64(str);

    // Assert
    EXPECT_EQ(expectedStr, result);
}

TEST(Kudryashov_Nikita_Base64_Encoder_test, Can_encode_mixed_string) {
    // Arrange
    string str = "R#Vr=x^Itpwi9V)**dvB@vT-Rfl4Gc";
    string expectedStr = "UiNWcj14Xkl0cHdpOVYpKipkdkJAdlQtUmZsNEdj";

    // Act
    string result = Base64Encoder::strToBase64(str);

    // Assert
    EXPECT_EQ(expectedStr, result);
}

TEST(Kudryashov_Nikita_Base64_Encoder_test, Can_decode_letter_string) {
    // Arrange
    string str = "Z1BleHRMa0dKU253TW9OQ3BuSHBUemRlekFIdG0=";
    string expectedStr = "gPextLkGJSnwMoNCpnHpTzdezAHtm";

    // Act
    string result = Base64Encoder::base64ToStr(str);

    // Assert
    EXPECT_EQ(expectedStr, result);
}

TEST(Kudryashov_Nikita_Base64_Encoder_test, Can_decode_number_string) {
    // Arrange
    string str = "MDEzNjYyODg0MzExMjY2MTY0NDQ4MDIyNzEyNzgy";
    string expectedStr = "013662884311266164448022712782";

    // Act
    string result = Base64Encoder::base64ToStr(str);

    // Assert
    EXPECT_EQ(expectedStr, result);
}

TEST(Kudryashov_Nikita_Base64_Encoder_test, Can_decode_symbol_string) {
    // Arrange
    string str = "JisjIS0rJF8hLSYkISQhJkAlK0AqKz0qXi0kKist";
    string expectedStr = "&+#!-+$_!-&$!$!&@%+@*+=*^-$*+-";

    // Act
    string result = Base64Encoder::base64ToStr(str);

    // Assert
    EXPECT_EQ(expectedStr, result);
}

TEST(Kudryashov_Nikita_Base64_Encoder_test, Can_decode_mixed_string) {
    // Arrange
    string str = "UiNWcj14Xkl0cHdpOVYpKipkdkJAdlQtUmZsNEdj";
    string expectedStr = "R#Vr=x^Itpwi9V)**dvB@vT-Rfl4Gc";

    // Act
    string result = Base64Encoder::base64ToStr(str);

    // Assert
    EXPECT_EQ(expectedStr, result);
}
