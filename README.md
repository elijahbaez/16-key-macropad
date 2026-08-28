\# ⌨️ Custom 16-Key Mechanical Macropad



A custom-built, programmable 16-key mechanical macropad powered by an RP2040 microcontroller. Designed to streamline custom PC building operations by automating hardware-level system-testing workflows, replacing repetitive manual data entry and testing sequences with a dedicated hardware interface.



\## 📸 Project Showcase

\*\*\*



\### KiCad PCB Design \& Routing



Engineered from scratch using KiCad. Features a custom 4x4 switch matrix with a 1N4148 diode array to completely eliminate key ghosting. Routed using 2-layer traces, deliberately isolating horizontal rows on the bottom copper layer (blue) and vertical columns on the top copper layer (red) to guarantee optimal signal integrity.



!\[KiCad PCB Routing Design](images/pcb-routing.png)



\### QMK Firmware \& C++ Macro Layers



Powered by custom QMK firmware mapped specifically to the RP2040 GPIO layout. Programmed with 3 dedicated macro layers in C++ utilizing QMK's `process\_record\_user` state machine to automate redundant PC system-testing workflows, such as launching hardware telemetry/sensors, automated network ping tests, and instant task manager overrides.



!\[C++ Firmware Logic](images/firmware-code.png)

