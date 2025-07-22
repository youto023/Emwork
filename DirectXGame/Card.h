#pragma once
#include <string>

// 色の種類
enum class Color { Red, Blue, Green };

// 属性の種類
enum class Attribute { Power, Speed, Technique };

// カードクラス
class Card {
public:
	// コンストラクタ（初期化）
	Card(Color color, Attribute attribute, int score);

	// カード自体のスコアを取得
	int CalculateScore() const;

	// 別のカードとのコンボボーナスを計算
	int CalculateComboBonus(const Card& other) const;

	// メンバ変数（カードの情報）
	Color color;         // カードの色
	Attribute attribute; // カードの属性
	int baseScore;       // カードの基本点数
};