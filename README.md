# Rogic Reworked

A reworked build of **Rogic 4.0.1**, the block-based ("chip") programming tool for ROBOROBO school robot kits. You build a program by dragging chips onto the canvas. Rogic turns it into C, compiles it for the kit's ATmega8 controller and downloads it to the robot.

This is an unofficial, modified build. Rogic is © ROBOROBO Co., Ltd.

![Rogic Reworked main window: the Chips2 palette on the left and a ten-chip program on the canvas, with Forward, Steer, Distance, arcs, Backward, Combo, Line Follow and Stop chips](docs/screenshots/main-window.jpg)

## New in this build

### Drive chips (the *Chips2* palette tab)

A new palette tab with eleven chips for driving a two-wheeled robot without wiring up individual motors by hand.

<img src="docs/screenshots/chips2-palette.png" alt="The Chips2 palette: Forward, Backward, four arc chips, Steer, Stop, Distance, Line Follow and Combo, with the Motor lock switch below the category buttons" align="right" width="170">

| Chip | What it does |
| --- | --- |
| **Forward** / **Backward** | Run the selected motors (2- or 4-motor robot) at a chosen speed, optionally for a set number of seconds. |
| **L-Arc Fwd**, **R-Arc Fwd**, **L-Arc Bwd**, **R-Arc Bwd** | Drive one side only, so the robot pivots around the other wheel. |
| **Steer** | Turn left or right by a number of **degrees**. The turn time comes from the robot's calibrated full-spin time, with an optional multiplier. |
| **Stop** | Stop both wheels by **brake** (hold still, so a timed move ends exactly where the timing says) or **coast** (roll free). It can also wait afterwards. |
| **Drive Distance** | Drive forward or backward a distance in **centimetres**. The run time comes from the calibrated 100 cm time and is scaled by speed. The dialog warns when the speed is too low for a reliable distance. |
| **Line Follow** | A complete two-sensor line follower in one chip. See below. |
| **Combo** (Drive + Servo) | Set up to five servos (0–214), give them time to reach position, then drive forward, backward or spin for a set time. Afterwards the motors either stop or keep running. |

Every drive chip applies the robot's wheel-balance correction and the Motor lock setting (both described below). Each chip on the canvas shows its key setting, such as `R 90°`, `F 120cm` or `brake`. Click the small square in its top-right corner to open its dialog.

![The Steer dialog open over the canvas, set to turn right 90 degrees at speed 15](docs/screenshots/dialog-in-context.jpg)

| Forward | Forward, 4-motor robot |
| --- | --- |
| ![Motor Route dialog for Forward: two motors at speed 15 for 1.5 seconds](docs/screenshots/forward.png) | ![Motor Route dialog with the motor count set to 4, showing M1 to M4](docs/screenshots/forward-4-motors.png) |
| **Backward** | **Steer** |
| ![Motor Route dialog for Backward: two motors at speed 15 for 1.0 second](docs/screenshots/backward.png) | ![Steer dialog: direction Right, 90 degrees, speed 15, multiplier 1.0, 360 degree time 2.4 seconds](docs/screenshots/steer.png) |
| **Left arc, forward** | **Right arc, backward** |
| ![Arc Turn dialog for a forward left arc: only motor M2 runs, for 0.8 seconds](docs/screenshots/arc-left-forward.png) | ![Arc Turn dialog for a backward right arc: only motor M1 runs, for 0.8 seconds](docs/screenshots/arc-right-backward.png) |
| **Stop: brake** | **Stop: coast, then wait** |
| ![Stop dialog in brake mode, with a note on brake versus coast](docs/screenshots/stop-brake.png) | ![Stop dialog in coast mode with a 1.0 second wait afterwards](docs/screenshots/stop-coast.png) |
| **Drive Distance** | **Combo (Drive + Servo)** |
| ![Drive Distance dialog: forward 120 cm at speed 15, which runs the motors for 4800 ms](docs/screenshots/drive-distance.png) | ![Drive + Servo dialog: servo 1 at 100 and servo 2 at 160 for 0.5 s, then drive forward at speed 12 for 2.0 s, then stop](docs/screenshots/combo.png) |

### Line Follow chip

- **Basic dialog:** choose whether each motor is normal or reversed. If the robot drives backwards, reverse both; if it spins on the spot, reverse one.
- **Advanced settings…** set:
  - the left and right sensor ports (IN1–IN7)
  - whether the sensor reads HIGH or LOW over black
  - whether the line runs between the sensors or under both
  - base speed, turn speed and loop delay
  - the run mode: **forever**, **for N seconds** or **to the finish mark**
- The generated C is commented line by line ("drifting right, line under the left sensor"…), so it can be read in the source editor.

| Line Follow | Advanced settings |
| --- | --- |
| ![Line Follow dialog: Motor 1 and Motor 2 set to normal, with a hint about reversing motors and an Advanced settings button](docs/screenshots/line-follow.png) | ![Line Follow advanced dialog: sensors on IN1 and IN2, HIGH over black, line between the sensors, base speed 11, turn speed 4, checked every 10 ms, run to the mark](docs/screenshots/line-follow-advanced.png) |

![The RogicEditor next to the program, showing the generated C for the Line Follow chip: a while loop with commented branches for both sensors on the line, drifting right, drifting left and on course](docs/screenshots/generated-c-line-follow.jpg)

### Robot Setup (Setup ▸ Robot Setup…)

Calibrate the robot once, and every drive chip uses the result.

- **Wheel balance:** pick the faster wheel and the percentage it should run at. Drive chips slow that wheel so the robot tracks straight. The dialog previews the speeds actually sent to each wheel.
- **Movement timing:**
  - **Full spin (sec)** is used by Steer.
  - **100 cm (sec)** is used by Drive Distance.
- **Test spin** / **Test straight:** replace the current program with a single calibration chip (a 360° Steer or a 100 cm Drive Distance). Download it, watch where the robot stops, and adjust the timing until it's right.
- The calibration is kept in undo/redo and in the crash-recovery autosave. It is **not** written to saved `.rpj` files, so set it again after reopening a project.

![The Setup menu with its Robot Setup entry](docs/screenshots/setup-menu.png)

![Robot Setup dialog: the left wheel runs at 92 percent, with a preview of the speeds sent (15 becomes L14/R15, 10 becomes L9/R10, 5 stays L5/R5), full spin 2.6 s, 100 cm 3.8 s, Test spin and Test straight buttons, and the Motor lock checkbox](docs/screenshots/robot-setup.png)

![Pressing Test spin asks to replace the current program with a single 360 degree Steer chip](docs/screenshots/test-spin-confirm.jpg)

| After *Test spin* | After *Test straight* |
| --- | --- |
| ![The program replaced by Start, Steer L 360 degrees and Stop brake](docs/screenshots/test-spin-program.jpg) | ![The program replaced by Start, Distance F 100cm and Stop brake](docs/screenshots/test-straight-program.jpg) |

### Motor lock

A **MOTOR LOCK** switch in the main window, also in Robot Setup. When it is ON, every motor chip ends by setting both motors to 0 and holding for 0.5 s, so each move runs separately instead of blending into the next. Like the calibration, it isn't stored in `.rpj` files.

![The Motor lock switch, OFF and ON](docs/screenshots/motor-lock.png)

<img src="docs/screenshots/generated-c-drive.png" alt="Generated C with Motor lock ON: every move is followed by motor(0, DIR_CW, 0), motor(2, DIR_CW, 0) and delay(500), and the Combo chip sets servo1(100) and servo2(160) before driving" width="420">

### Look and feel

- New chips and their dialogs use a colour-coded theme by category: motor blue, sensor green, servo teal, delay amber and so on.
- When a palette tab holds more chips than fit, it scrolls with the **mouse wheel**.
- If a chip or dialog image is missing from the resources, Rogic draws a themed replacement instead of failing.

## Requirements

- Windows with **.NET Framework 4.6.2** or newer.
- **WinAVR-20100110** installed at `C:\WinAVR-20100110`, with its `bin` and `utils\bin` folders on `PATH`. Rogic calls `avr-gcc` and `avr-objcopy` to build the program.
- **CP210x USB-to-UART driver** for the robot's download cable. The driver is included in [Driver/CP210X](Driver/CP210X): use `Universal` on Windows 10/11 and `Origin` on older systems.

## Running

Run `Rogic.exe` from this folder. The DLLs, `Lib/` and `RogicRes/` must stay next to it. UI languages: English, Korean, Chinese and Russian.

If Rogic crashes, the error details are written to `runtime_error.log` (or `startup_error.log`) next to `Rogic.exe`.

## Layout

| Path | Contents |
| --- | --- |
| `Rogic.exe` | Main application |
| `ChipsDialogue.dll`, `ClientArea.dll`, `FixedArea.dll`, … | UI, chip dialogs, palette and canvas |
| `ISPDownloader.dll`, `STK500.dll` | Program download to the controller |
| `Bluetooth/` | Bluetooth module setup (master/slave pairing) |
| `Lib/` | AVR libraries and headers linked into every program (`libm8Api.a`, `libKitMD2013.a`, `schoolKits.h`) |
| `RogicRes/` | Cursors and icon |
| `Driver/CP210X/` | USB serial driver for the download cable |
| `msvcr100*.dll`, `shared32/64.dll` | Native runtime dependencies |
| `docs/screenshots/` | The screenshots in this README |

## Notes

The repository holds only compiled binaries, not source code. The reworked parts live in `Rogic.exe`, `ChipsDialogue.dll`, `ClientArea.dll` and `FixedArea.dll`.
