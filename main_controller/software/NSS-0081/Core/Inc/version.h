// version.h
#ifndef _VERSION_H_
#define _VERSION_H_

// メジャー.マイナー.パッチの形式で定義
#define SOFTWARE_MAJOR_VERSION   1     // 大きな機能追加や互換性のない変更
#define SOFTWARE_MINOR_VERSION   0     // 後方互換性のある機能追加
#define SOFTWARE_PATCH_VERSION   0     // バグ修正

// バージョン文字列生成のヘルパーマクロ
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

// バージョン文字列の生成（数値として展開される）
#define SOFTWARE_VERSION_STRING \
    TOSTRING(SOFTWARE_MAJOR_VERSION) "." \
    TOSTRING(SOFTWARE_MINOR_VERSION) "." \
    TOSTRING(SOFTWARE_PATCH_VERSION)

// ビルド情報の構造体
typedef struct {
    const char *version;    // バージョン文字列
    const char *buildDate;  // ビルド日付
    const char *buildTime;  // ビルド時刻
} version_info_t;

extern const version_info_t VERSION_INFO;

#endif /* _VERSION_H_ */