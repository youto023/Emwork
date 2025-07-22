#include "Card.h"

// コンストラクタ
Card::Card(Color color, Attribute attribute, int score) : color(color), attribute(attribute), baseScore(score) {}

// カード単体のスコアを返す
int Card::CalculateScore() const { return baseScore; }

// コンボボーナスを計算する関数（色×色、属性×属性）
int Card::CalculateComboBonus(const Card& other) const {
	int bonus = 0;

	// --- 色のコンボ判定 ---
	if ((color == Color::Red && other.color == Color::Green) || (color == Color::Green && other.color == Color::Red)) {
		// 赤＋緑 → 攻撃的なコンボ
		bonus += 3;
	} else if ((color == Color::Red && other.color == Color::Blue) || (color == Color::Blue && other.color == Color::Red)) {
		// 赤＋青 → 対立するためペナルティ
		bonus -= 2;
	} else if (color == other.color) {
		// 同じ色 → 統一感のボーナス
		bonus += 1;
	}

	// --- 属性のコンボ判定 ---
	if ((attribute == Attribute::Power && other.attribute == Attribute::Speed) || (attribute == Attribute::Speed && other.attribute == Attribute::Power)) {
		// パワー＋スピード → 爆発的な攻撃力
		bonus += 4;
	} else if ((attribute == Attribute::Technique && other.attribute == Attribute::Speed) || (attribute == Attribute::Speed && other.attribute == Attribute::Technique)) {
		// テクニック＋スピード → 素早く巧みな攻撃
		bonus += 2;
	} else if (attribute == other.attribute) {
		// 同じ属性 → 安定感・特化ボーナス
		bonus += 1;
	}

	// コンボによるスコア増減を返す
	return bonus;
}