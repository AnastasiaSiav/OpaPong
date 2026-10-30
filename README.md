# OpaPong

A 2-player Pong game written in C++ using the **SGG (Simple Graphics Library)**.
Developed as a university project for the course *Computer Programming with C++* (2024–25).

## Gameplay

Two players share the same keyboard and bounce the ball back and forth.
When the ball reaches a goal on either side, the score increases and a new ball is spawned.

| Player | Up | Down |
|---|---|---|
| Left paddle | `↑` | `↓` |
| Right paddle | `W` | `S` |

## Code structure

The game is built around a polymorphic class hierarchy:

```
GameObject
└── MovingObject
    └── Rectangle
        └── CollidingObject
            ├── Ball
            ├── Goal
            └── Player
                ├── Player1
                └── Player2
```

- **GameObject**: abstract base class with virtual `update()` and `draw()`.
- **GameState / Game / Level**: hold the game objects and the score, and run the main loop.
- Game objects are created dynamically and stored in `std::vector<GameObject*>`. Dead objects are removed and deleted every frame.
- Collisions use axis-aligned rectangles.

## Building

Requirements: Windows, Visual Studio (C++), and the SGG library.

1. Clone the repository.
2. Create a `lib/` folder next to `OpaGame.sln` and copy the SGG library files (`sgg.lib`, `sggd.lib`) into it. They are not included in this repository.
3. Make sure the SGG DLLs are available when you run the executable.
4. Open `OpaGame.sln` in Visual Studio, build, and run.

The game loads its images, sounds and font from the `assets/` folder. Run the game with that folder next to the executable or set as the working directory.


