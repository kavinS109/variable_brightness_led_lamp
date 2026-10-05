# Bill of materials — ESP32 LED and encoder project

Prepared 5 October 2026. Currency: USD. Quantities are for one assembly.

Estimated component cost: **$17.85**, rounded planning budget **$18**. Allow roughly **$15–$25 for components**, excluding shipping, sales tax, tariffs, PCB/perfboard, wire, enclosure, encoder knob, power adapter and USB cable. Prices below are rounded budgeting allowances, not a supplier quote or a guaranteed purchasable cart. Pack minimums may increase checkout cost.

| Reference labels | Qty | Component / specification | Manufacturer / part | Est. unit | Est. extended |
|---|---:|---|---|---:|---:|
| R_LED1–R_LED5 | 5 | 91 Ω, ±5%, ¼ W, axial carbon-film resistor | Yageo CFR-25JR-52-91R | $0.10 | $0.50 |
| R_Base | 1 | 240 Ω, ±5%, ¼ W, axial carbon-film resistor | Yageo CFR-25JR-52-240R | $0.10 | $0.10 |
| R_Base_PD | 1 | 47 kΩ, ±5%, ¼ W, axial carbon-film resistor; base pulldown | Yageo CFR-25JR-52-47K | $0.10 | $0.10 |
| R_ENC_A, R_ENC_B | 2 | 10 kΩ, ±5%, ¼ W, axial carbon-film resistor | Yageo CFR-25JR-52-10K | $0.10 | $0.20 |
| R_BTN | 1 | 10 kΩ, ±5%, ¼ W, axial carbon-film resistor | Yageo CFR-25JR-52-10K | $0.10 | $0.10 |
| D1–D5 | 5 | Blue LED, 5 mm through-hole, clear lens, 30° viewing angle | Inolux INL-5AB30 | $0.50 | $2.50 |
| C_ENC_A, C_ENC_B | 2 | 0.01 µF / 10 nF, ±5%, ceramic capacitor | Generic; voltage rating, dielectric and footprint to select | $0.30 | $0.60 |
| C_BTN | 1 | 0.1 µF / 100 nF, ±5%, ceramic capacitor | Generic; voltage rating, dielectric and footprint to select | $0.50 | $0.50 |
| Q1 | 1 | 2N3904 NPN transistor, TO-92, 40 V, 200 mA maximum | Diotec 2N3904; packaging suffix to select | $0.25 | $0.25 |
| U1 | 1 | ESP32 DEVKIT V1 development board | DOIT / compatible; exact supplier and pin count to select | $8.00 | $8.00 |
| J1 | 1 | 5.5 × 2.1 mm DC barrel jack, right-angle, through-hole PCB mount | Tensility 54-00166 | $1.00 | $1.00 |
| ENC1 | 1 | Rotary encoder with momentary pushbutton | Bourns PEC11H series; full ordering code to select | $4.00 | $4.00 |
| **Total** | **22** | **10 resistors, 5 LEDs, 3 capacitors, 1 transistor, 1 board, 1 jack, 1 encoder** | | | **$17.85** |


## Consolidated resistor purchase quantities

| Resistance | Quantity | Specification |
|---|---:|---|
| 91 Ω | 5 | Yageo, ±5%, ¼ W |
| 240 Ω | 1 | Yageo, ±5%, ¼ W |
| 47 kΩ | 1 | Yageo, ±5%, ¼ W |
| 10 kΩ | 3 | Yageo, ±5%, ¼ W |


## Datasheet sources

- INL-5AX30 series_DS(1).pdf: blue INL-5AB30 variant, electrical characteristics and ordering table.
- 54-00166_DS(1).pdf: Tensility right-angle 5.5 × 2.1 mm barrel jack.
- PEC11H_DS(1).pdf: Bourns encoder ordering options and suggested filter circuit.
- 2n3904_DS(2).pdf: Diotec 2N3904 ratings and TO-92 package.


## Price references checked 5 October 2026

Price pages can change. Budget allowances intentionally use rounded values and mix supplier references; they are not a single-vendor quote.

- Yageo 91 Ω resistor: DigiKey lists $0.10 at quantity 1. Other resistor values use the same $0.10 allowance rather than separately verified quotes: https://www.digikey.com/en/products/filter/through-hole-resistors/91-ohms/53
- Inolux INL-5AB30: product identified at DigiKey; a secondary listing showed $0.51. $0.50 is a budgeting allowance, not verified DigiKey pricing: https://www.digikey.com/en/products/detail/inolux/INL-5AB30/7604625 and https://www.lanka-micro.com/manufacturers/Inolux?page=18
- Tensility 54-00166: manufacturer page showed $0.53; quantity conditions were not established, so $1.00 is allowed: https://www.tensility.com/products/54-00166
- PEC11H encoder: Mouser PEC11H family listing showed $3.37 for PEC11H-4020F-S0016 at quantity 1: https://www.mouser.com/en/c/passive-components/encoders/?m=Bourns&with+switch=Pushbutton+Switch
- ESP32 DEVKIT V1: marketplace listing showed $7.19 for a 30-pin development board; $8.00 allowed, supplier/model to confirm: https://www.walmart.com/ip/17700363178
- Diotec 2N3904: DigiKey related-product listing showed $0.14; $0.25 allowed: https://www.digikey.com/en/products/detail/onsemi/2N3904/25602699
