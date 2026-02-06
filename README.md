# Event-Driven FSM Controller (Software Simulated)

## Overview

This project demonstrates a **clean, event-driven embedded firmware architecture** using **multiple Finite State Machines (FSMs)**. It is written as a **software-simulated project** (runs on a PC) to focus on **logic, structure, and design thinking**, not hardware-specific code.

The goal of this project is to show how real embedded systems are designed using **events, states, and clear separation of responsibilities**.

---

## Key Features

* Event-driven design (no blocking delays)
* Two independent FSMs working together
* Clear separation between input handling and application logic
* Easily portable to real hardware (Arduino / STM32 / ESP32)

---

## System Architecture

```
Button Input
     │
     ▼
Button FSM  ──── generates events ────▶  Application FSM
                                             │
                                             ▼
                                        LED / Mode Logic
```

* **Button FSM**: Detects press patterns and generates events
* **Application FSM**: Decides system behavior based on events

---

## Finite State Machines

### 1. Button FSM (Input Layer)

**Responsibility:** Detect button press patterns and generate events

**States:**

* IDLE
* PRESSED

**Events Generated:**

* `SHORT_PRESS`
* `LONG_PRESS`

> Debouncing is intentionally omitted to keep the focus on FSM architecture.

---

### 2. Application FSM (Behavior Layer)

**Responsibility:** Control system behavior based on events

**States:**

* OFF
* ON
* BLINK_SLOW
* BLINK_FAST

**Events Consumed:**

* `SHORT_PRESS`
* `LONG_PRESS`
* `TIMEOUT`

Each state clearly defines how the system reacts to different events.

---

## File Structure

```
event-driven-fsm-controller/
│
├── main.c            // Main loop, FSM execution
├── events.h          // Common event definitions
├── button_fsm.c      // Button FSM logic
├── button_fsm.h
├── app_fsm.c         // Application FSM logic
├── app_fsm.h
├── README.md         // Project documentation
```


