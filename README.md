# 🏰 ChamberCrawler3000 (CC3k)  
*CS246 Spring 2025 Final Project*

## 📜 Overview

**ChamberCrawler3000 (CC3k)** is a simplified turn-based rogue-like dungeon crawler built in C++. The player explores a 5-floor dungeon, defeats enemies, collects treasure, and tries to escape alive. Inspired by classic rogue-likes, CC3k features grid-based movement, randomized maps, enemy AI, and player race customization.

This project is designed with a strong emphasis on **object-oriented programming**, including the use of **inheritance, polymorphism, and design patterns** (e.g. Decorator, Factory).

---

## 🧱 Architecture

### 🔧 Core Components

- **Character** (abstract base): shared logic for all entities with HP, Atk, Def, attack/move behavior.
- **PC (PlayerCharacter)**: Decorator-based design to inject race-specific traits (e.g. Troll regen, Drow potion boost).
- **Enemy**: Subclassed per type (e.g. Elf, Orc, Halfling), each with unique combat behavior.
- **Item**: Base class for `Potion` and `Gold`, supports usage and interaction.
- **Cell / Floor / Chamber**: Represent the dungeon map, rooms, and walkable tiles.
- **Gameplay**: The main game loop controller, handling input, player turns, enemy actions, and floor transitions.
- **Display**: Responsible for ASCII-based visual output with color support.

---

## 🕹️ Gameplay Flow

1. **Start**: Choose race (Shade, Drow, Vampire, Troll, Goblin).
2. **Game Loop**:
   - Enter command (move, attack, use potion, etc.)
   - Player action → status update
   - Enemy AI actions
   - End-of-turn effects (e.g., Troll regen)
   - Check for death or floor transition
3. **Win Condition**: Reach the stairs on Floor 5.
4. **Lose Condition**: Player HP drops to 0.

---

## 🧠 Key Features

- ✅ Turn-based gameplay
- ✅ Decorator pattern for PC race abilities
- ✅ Enemy AI (attack if adjacent, otherwise random move)
- ✅ Gold and potion items with floor-dependent effects
- ✅ Colored terminal rendering
- ✅ Command-line input handling
- ✅ Support for predefined map file input
- ✅ Floor randomization
- ✅ Clean, modular OOP design

---

## 🔤 Controls

| Command | Action |
|---------|--------|
| `no`, `so`, `ea`, `we`, `ne`, `nw`, `se`, `sw` | Move in direction |
| `a <dir>` | Attack enemy in direction |
| `u <dir>` | Use potion in direction |
| `f` | Freeze/unfreeze enemy movement |
| `r` | Restart game |
| `q` | Quit game |

---

## 🧪 How to Compile & Run

```bash
make
./cc3k
# Game_Project_cc3k
