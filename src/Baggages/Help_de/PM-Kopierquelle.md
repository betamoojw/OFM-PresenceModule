### Kopierquelle

* **Herstellerwerte** - Kopiert die Hersteller-Voreinstellung der Sensorwerte in das eingestellte Ziel
* **konstanten Wert** - Kopiert einen konstanten (eingebbaren) Wert in das eingestellte Ziel
* **frühere Kalibrierung mit Empfindlichkeit** - Kopiert die Werte, die die bisherige Kalibrierungsfunktion passend zur Empfindlichkeit ermittelt hat, in das eingestellte Ziel. Dabei kann die Empfindlichkeit angegeben werden. Dies ist für all diejenigen gedacht, die mit der bisherigen Firmware gute Ergebnisse erzielt haben und keine weiteren Einstellungen vornehmen wollen.
* **Stichprobe 1: Maximalwert + Offset** - Kopiert die ermittelten Werte für den Maximalwert der Stichprobe 1 zuzüglich eines eingebbaren Offsets in das eingestellte Ziel. Hier ist meist nur Trigger ein sinnvolles Ziel. Eignet sich z.B. um initial Stichprobe + 500 in alle Trigger zu übertragen.
* **Stichprobe 1: Standardabweichung + Offset** - Kopiert die ermittelten Werte für die Standardabweichung der Stichprobe 1 zuzüglich eines eingebbaren Offsets in das eingestellte Ziel. Hier ist meist nur Halten ein sinnvolles Ziel. Sollten die Durchschnittswerte dazu führen, dass der Sensor eine Dauerpräsenz erkennt, ist die Standardabweichung ein guter höherer Wert für passable Ergebnisse.
* **Stichprobe 1: Durchschnitt + Offset** - Kopiert die ermittelten Werte für den Durchschnitt der Stichprobe 1 zuzüglich eines eingebbaren Offsets in das eingestellte Ziel. Hier ist meist nur Halten ein sinnvolles Ziel. Eignet sich z.B. um initial Durchschnitt + 0 in alle Halten zu übertragen.
* **Stichprobe 2: xxxx** - analog zu den Stichprobe 1-Funktionen
* **Differenz + Offset** - Kopiert die berechneten Differenzwerte zuzüglich eines eingebbaren Offsets in das eingestellte Ziel. Das spart das manuelle Übertragen von berechneten Werten in die jeweiligen Ranges.
