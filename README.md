# Orbion The OpenSource 3D Space Mouse

[![Stars](https://img.shields.io/github/stars/FaqT0tum/Orbion_3D_Space_Mouse.svg)](#)
[![Total Downloads](https://img.shields.io/github/downloads/FaqT0tum/Orbion_3D_Space_Mouse/total.svg)](https://github.comFaqT0tum/Orbion_3D_Space_Mouse/releases)

### はじめに
こちらは元のリポジトリのOrbion The OpenSource 3D Space Mouseをフォークしたものです。
素晴らしい物を公開してくれた作者である、[FaqTotum](https://github.com/FaqT0tum)さんに敬意を表します。
全ての権利は元のリポジトリの制作者に帰属されます。

以下は元のリポジトリを機械翻訳した内容になります。

### 次のニュース
最新のアップデートを確認するためには公式のDiscodeチャンネルを確認してください。
 [Discord](https://discord.gg/tgut7grRTV)

### 現在のバージョン
- Hardware 2.5 (19/03/2022)
- Firmware 0.26.4 (19/03/2022)

![](IMG/main.png)
![](IMG/orbion_stl_map.png)

すべてのパーツは、お好みの素材で印刷できます (ABS と ASA の収縮率に注意してください)。
ただし、「cuschio」および「wire_clips」パーツは TPU Shore 95A または 85A でなければなりません。

![](IMG/orbion_sch.png)
![](IMG/orbion_menu.png)

マウスには任意の設定を行うことができます。
例えばFusion 360向けに以下のように設定してみましょう。
- 任意のキーをSHIFTキーに設定する。
- JoyStick モードをAutodeskに設定する。
- 他の 3 つのボタンはお好みで設定します。

このように設定すると、ノブを動かすと軌道が動き、SHIFTキーとして割り当てたキーを押しながらノブを動かすとCADソフト上でPANをすることができます。

# ブラウザからマウスのCADデータを見る

以下にアクセスすることで、ブラウザ上からいつでもCADデータの閲覧をすることができます。
[LINK](https://a360.co/3NWq3W3)

![](IMG/orbion_fusion.jpeg)


# 注意事項

- 不良なコンポーネントの製造や、プリンターのキャリブレーションによる高さの誤りによって生じた問題については、チケットは作成されません。
これらは固有の問題であり、プロジェクトに起因するものではありません。
- 精度と流動性を高めるために、ノブの下にフォームリングを置くか、ジョイスティックに Cushion_TPU と誘電潤滑剤を入れることをお勧めします。
- 印刷する前に、エンコーダー穴の中心距離に注意してください。14mm と 17mm の 2 つの拡散サイズが利用可能です (ファイル Enc_holder と Knob_axis)。
- ABS を使用する場合、収縮の問題に対する通常の予防措置を講じないと、一部の寸法が正しくない可能性があることを知っておくことをお勧めします。

いずれにしても、プリンターの寸法パラメーターが正しいことを確認してください。

# ファームウェア

## ファームウェアの開発環境

開発環境には以下を使用します。
- [Visual Studio Code](https://code.visualstudio.com/)
- [Platform IO](https://platformio.org/)

## ファームウェアの書き込み

ファームウェアをフラッシュするための手順を説明したPDFファイルがあります。
[HowToFlashing](HowToFlashing.pdf)

# ソーシャルメディア

- [Instagram](https://www.instagram.com/faq_t0tum/)
- [Discord](https://discord.gg/tgut7grRTV)
- [YouTube](https://www.youtube.com/channel/UCHJ_528ZI0BcSU-QA8kIJlg)
- [PrusaPrinter](https://www.prusaprinters.org/social/218145-faqtotum/about)

# コーヒーを買ってあげてください。

ORBION プロジェクトにいたく感動を受けましたよね？
なんと今なら以下から作者にコーヒーを買ってあげることができます。
[PayPal](https://www.paypal.me/MattiaRusso308?locale.x=it_IT)

# ソフトウェア互換性

サポートされている CAD および 3D Sculptor
- Fusion360
- Autoocad
- SolidWork
- Solid EDGE
- Onshape
- Ansa
- ZBrush
- Blender
- Adobe Suite
- Rhino
- FreeCAD

# ハードウェアの部品構成

コンポーネント:
- M3x15 (3pcs)
- M3x6 or M3x8 (5pcs)
- M3x10 (4pcs)
[M3 Kit](https://s.click.aliexpress.com/e/_9R4lDe)
- [Insert 5x4 or 5x5 (Diameter x Height) M3 (13pcs)](https://s.click.aliexpress.com/e/_9yVx2u)
- [Oled 1.3" I2C](https://s.click.aliexpress.com/e/_AtYDV6)
- [Encoder (KY-040)](https://s.click.aliexpress.com/e/_AmjV9a)
- [Joystick (KY-023)](https://s.click.aliexpress.com/e/_A8hY9K) （重要：ジョイスティックのシャフトは4mmである必要があります）
- [Arduino Pro Micro](https://s.click.aliexpress.com/e/_AYt9zi) （注意: USB機器として作成するため、ATMEL32U4プロセッサを搭載したARDUINO PRO MICROを使用することが重要です。）
- [Push Button 8mm x3](https://s.click.aliexpress.com/e/_ADGxZS)
- [Cable 28awg](https://s.click.aliexpress.com/e/_A6xGln)
- [Neopixel Strip WS2812B](https://s.click.aliexpress.com/e/_APd9lZ) （重要：1M 60 IP30 バージョンのみを選択してください)
- [Microswitch (Reset)](https://s.click.aliexpress.com/e/_AZhwpN)
- [Axial Bearinger F8-22M](https://s.click.aliexpress.com/e/_ArBcYb)


# ライセンス

ライセンスは機械翻訳です。原文も以下に載せます。

### [Attribution-NonCommercial-NoDerivatives 4.0 International](https://creativecommons.org/licenses/by-nc-nd/4.0/)
<a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-nd/4.0/88x31.png" /></a><br />

以下の行為は自由に行えます:
- 共有 — あらゆる媒体または形式で素材をコピーおよび再配布

以下の条件に従って:
- 帰属 — 適切なクレジットを表示し、ライセンスへのリンクを提供し、変更があった場合はその旨を明記する必要があります。これは、合理的な方法で行うことができますが、ライセンサーがあなたまたはあなたの使用を承認していると示唆する方法は許可されません。
- 非営利 — 素材を商用目的で使用することはできません。
- 改変禁止 — 素材をリミックス、変形、または構築する場合、変更された素材を配布することはできません。

### [Attribution-NonCommercial-NoDerivatives 4.0 International](https://creativecommons.org/licenses/by-nc-nd/4.0/)
<a rel="license" href="http://creativecommons.org/licenses/by-nc-nd/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-nd/4.0/88x31.png" /></a><br />

You are free to:
- Share — copy and redistribute the material in any medium or format

Under the following terms:
- Attribution — You must give appropriate credit, provide a link to the license, and indicate if changes were made. You may do so in any reasonable manner, but not in any way that suggests the licensor endorses you or your use.
- NonCommercial — You may not use the material for commercial purposes.
- NoDerivatives — If you remix, transform, or build upon the material, you may not distribute the modified material.

### 他にも共有したいMODがあれば・・・
[Discord](https://discord.gg/tgut7grRTV)チャンネルにログインし、作者に連絡して「Yours_Creations」に追加をお願いしてください。
