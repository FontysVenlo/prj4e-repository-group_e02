




# Project charter

### Embedded application – Duck
##### Author: group 2 <br> Location: Fontys University, Tegelseweg 255, 5912 BG Venlo <br> Version: v1.4  <br>  Date: 06.04.2025




## **Abstract:**
This project aims to develop an amphibious robotic duck that mimics the appearance and behaviour of a real duck while freeing of the need for animal care. Designed for outdoor ponds, it offers a lifelike alternative for the presence of a duck without the responsibilities of keeping one. By combining embedded systems with autonomous movement the project aims to create a functional, self-sustaining robotic companion for outdoor settings in order to replace ducks.

**Acronyms**


|**Abbreviation**|**Meaning**|
| :- | :- |
| KPI | Key Performance Indicator(s) |
| WBS | Work Breakdown Structure |


<br>
<br>


**Version history**

|**Version**|**Date**|**Comment**|
| :-: | :-: | :-: |
| 0\.1 | 14.03.2025 |First draft|
| 1.1 | 25.03.2025 | Initial chapters notes |
| 1.2 | 31.03.2025 | Chapters 1, 3, abstract, Introduction |
| 1.3 | 05.04.2025 | Chapters 2, 4, 7, WBS |
| 1.4 | 06.04.2025 | Chapters 5, 6 |


---

**Table of content** 

[1. Introduction](#1-introduction)

[2. Business case](#2-business-case)

[3. Approach](#3-approach)

[3.1 In scope](#3-approach)

[3.2 Out of scope](#3-approach)

[4. Deliverables](#4-deliverables)

[5. Quality management](#5-quality-management)

[6. Prerequisite](#6-prerequisite)

[7. Success criteria](#7-success-criteria)

[Appendix](#appendix)

[A: Work breakdown structure]( )







# 1. Introduction
The project focuses on designing and building a functional prototype capable of autonomous movement on water. The robotic duck will feature realistic behaviour such as floating, swimming, and quacking while maintaining energy autonomy for outdoor operation. Development efforts will include hardware design, embedded control systems, power and motor management, sensor integration, software implementation, etc. <br>
Over the course of the semester, the project will progress through research, hardware development, software implementation, and testing phases. The hardware will primarily cover essential materials, including motors, sensors, waterproofing components, and embedded processing units. Key challenges include ensuring waterproofing and durability, achieving lifelike movement and other behaviours, as well as balancing autonomous behaviour with potential user control.
By addressing these challenges and delivering a reliable, autonomous system, the project aims to create an innovative and practical robotic companion for outdoor environments.








# 2. Business case

There is currently no widely available robotic duck on the market that convincingly mimics the appearance and behaviour of a real duck. For pond owners and outdoor enthusiasts who wish to enjoy the presence of the bird without the responsibilities of caring for live animals, this project fills out the empty market gap. Robotic duck targets that gap, focusing on developing a lifelike amphibious robotic duck that can autonomously navigate water, respond to environmental changes in realtime, and produce realistic quacking sounds.

Besides its potential as a product with market prospects, this project also serves an important educational purpose. It provides a practical, hands-on opportunity to deepen developers' understanding of embedded systems, including areas such as motor control, sensor integration, wireless communication, and power management.

From an academic standpoint, the primary goal is to successfully complete and pass the Project 4 module. The amphibious robotic duck aligns well with the learning outcomes of the course, as it incorporates a broad range of embedded technologies and team collaboration. This combination of commercial potential and academic value makes the project both an intresting prototype and an effective learning platform.




# 3. Approach
The project will be conducted in a hybrid scrum way of working with a sprint length of 1 week. A Kanban board will be used to take track of all the use cases that have to be completed and a planning meeting will be used to plan the work for every sprint. Also daily stand up meetings will be used to keep every team member on track with the state of the project.
To achieve the projects objectives the project will be planned first by ordering and researching all the necessary components needed for the robot to function. On arrival of the components, the project team will use two project weeks with 20 hours of weekly working time to build actual initial hardware and at the end of the semester there will be additional 3 weeks of 40 hours of weekly working time to finish and complete the robot. Every other normal week a minimum of 5 hours will be spend working on the project.
### 3.1 In Scope 
The must have scope functionality of the duck robot includes:
- A working distance sensor that detects the shore
- An algorithm that turns the robot when it detects the shore and steers it into a different direction
- A driving system that lets the duck move straight with the help of a compass.
- A working speaker that plays different "Quack" sounds
- It needs to operate on its own for at least an hour
- A low power mode where the duck does not leave the shore anymore after finding it

The might haves include:
- A remote control that takes over the duck
- Movement on land
### 3.2 Out of Scope
- It will not be able to fly
- It will not be able to throw flames
- It will not be able to lay eggs
- It will not include a camera
- It will not be able to transition from water to ground
- It will not detect other ducks or interact with them

# 4. Deliverables 
The project will result in a set of defined deliverables, which represent the main outcomes of the development process. These deliverables serve as a mutual point of reference for project team members and other stakeholders to align expectations and track progress. The final results will reflect both the technical functionality and the organizational goals of the project.

### 4.1 Hardware and Component deliverables:
- A complete component list documenting all parts used in the final product, including motors, motor drivers, control modules, sensors, power units, and other relevant electronics or mechanical parts.
- A reusable power solution, rechargeable battery with efficient management and safety features.
- A distance sensor integrated into the final model in an optimal position to detect obstacles with high efficiency and accuracy.
- A speaker module playing preuploaded quacking tracks within reasonable volume range.
- A fully operational propulsion system for water-based enviroment with two Mississippi-type paddle wheels.
- An outer frame resembling a duck.

### 4.2 Software deliverables:
- Fully developed embedded software controlling autonomous behavior, sensor input handling, obstacle avoidance, sound playback, and power management logic.
- The code must be well-structured and maintainable, with proper commenting and implementation of software development design principles (e.g., single responsibility, separation of concerns, fail-safe logic).
- Implementation of a low battery mode, need for keeping the duck near the shore when battery charge falls below a critical level.
- Optional support for RC control.


### 4.3 Final Robot deliverable:
- Fully functional amphibious robotic duck, capable of operating autonomously on water, demonstrating stable navigation, sensor-based behavior, and basic interaction through sound.
- The robot capable of straight-line and manouvering movement, with the ability to adjust course automatically based on environmental input.
- All core systems should be sustained via onboard rechargeable battery power.
- The duck has a life-like visual appeal, fitting its intended use in outdoor ponds as a realistic animal alternative.
- The final model includes basic safety features, such as automatic shutdown in the event of critical faults or water damage detection.
- Supporting documentation delivered alongside the robot, including system schemas, wiring diagrams, component specifications, assembly instructions, and usage guidelines.


# 5. Quality management 
We are being evaluated on our project mainly through portfolio-based grading, so while it is nice to have the robotic duck working like it is intended.The focus is how we arrive there—how we experiment, what we discover, how we write it down on the way, and what we learn. 

### 5.1 Quality Goals

-The duck should be able to swim in water alone (or half-way alone at least) and perform programmed behavior.
-We want to make sure the key features, like movement, power, and code are working like intended.
-We have selected a lower voltage motor in order to save power consumption and total weight, which will ensure that our duck doesn't sink.
-We're also trying to get a good balance between the power supply's weight and how long it will propel the duck for.
-The plan is to do a lot of experimenting (such as trying different motor settings, wheel diameters, and power supply) and document what we find out to have a nice overview of our test results. This way we can improve the duck and find the perfect settings.

### 5.2 Quality Assurance

-We will start testing in smaller water containers like bathtubs or buckets before we move on to the "sea" on campus.
-Since waterproofing is a risky process, we will test the circuit separately outside of the duck first. That way, we won't be risking breaking equipment pieces too early.
-Every test, setup, and output that we do will be recorded in our team's GitHub repository, aswell as photos, comments, and observations too.

### 5.3 Quality Control

-With each test we perform, we'll check how well the duck can move, turn, and respond to commands.
-Before any water-test, we will check everything for waterproofing (visible and potentially in dunk tests) to ensure they are properly shut.
-When breaking something or getting it working incorrectly, we will write down or record that, work out what went wrong, and make changes before re-testing it.

### 5.4 Standards

-We're keeping our code clean and tidy and utilizing GitHub to track every branch, modification, and team feedback.
-Our team collaborates closely, sharing knowledge and keeping each other updated to ensure we're all involved and learning from every part of the project.

### 5.5 Team Roles

-Everyone is currently working on all aspects of the project. Like hardware, software, design, waterproofing, etc.
-If we ever do end up dividing the work later on, we'll still continue to inform each other so that all of us are aware of what's happening and can learn from each part of the project.



# 6. Prerequisite
There are some thinks which needs to be done tille we can completely start with building the robotic duck.

### 6.1 Parts and Components

-The university will be providing the ESP32 LoRa module. We haven't made all the details final for all aspects, but we did decide on a low-voltage motor so the build is light and is lower on power consumption.
-For power, we will explore a setup that has some combination of weight to runtime so the duck remains stable while running long enough to thoroughly test it.
-We will start with borrowed batteries from the university, and after we get a feel for what will work, we will purchase more suitable ones if needed.

### 6.2 Base Setup and 3D Printing

-We found an open-source design for the water wheels that looks good. We'll try it on and see how well it fits and works before committing.
-Our first tests will only use the plain duck base (no electronics) to see how it floats, how stable it is, and how much weight it can carry safely.

### 6.3 Control and Communication

-Wireless connection with the LoRa won't be important in this project. Autonomous movement is our top priority.
-For early testing, we’ll probably attach a rope to the duck so we can easily recover it. If everything works well, we’ll try adding remote control using RC modules later on.


### 6.4 Testing Environment

-We will start small—bathtubs, buckets, etc.—and work our way up to campus sea for full-scale testing.
-During early tests, we’ll also look at how much weight the base can handle before it becomes unstable or starts sinking.
-Safety of components is key—so we’ll avoid putting any electronics on the duck until we’re confident it can float reliably.

### 6.5 Risks

-There’s a chance things might go wrong in the water—like motors failing, the duck flipping, or waterproofing not holding up.
-Power issues (like weak batteries, unstable connections, or underpowered components) could also be a problem.
-To handle this, we’ll test things step by step, starting with the basics and building up once we’re confident in each part.



# 7. Success criteria
The success of the amphibious robotic duck project will be evaluated based on a set of measurable objectives, definitions of completion (acceptance criteria), and key performance indicators (KPIs). These criteria are intended to ensure that the system achieves its primary purpose — providing a life-like, self-operating duck for outdoor pond environments while performing safely in realistic conditions.

### 7.1 Measurable Objectives
The main measurable functionality of the robotic duck is its ability to autonomously navigate a water-based environment using the paddle-wheel system. This includes smooth movement, direction control, and responsive navigation. Additionally, onboard sensors must detect obstacles and enable the robot to avoid them in real-time without manual intervention. A built-in speaker module must also be capable of playing a selection of life-like quacking sounds to enhance realism.

For a more detailed breakdown of technical expectations refer to [Deliverables](#4-deliverables) chapter.

### 7.2 Acceptance Criteria
The project will be considered complete when the following conditions are met:
- The robotic duck maintains stable movement on water and can adjust its trajectory based on data from onboard obstacle detection sensors.
- The system is capable of operating for at least 60 minutes on a single charge under average load conditions, including motor and sensor activity.
- The software supports secondary modes, such as a low battery mode, which automatically limits operation and keeps the duck near the shoreline once power drops below a predefined threshold.
- The duck emits quacking sounds at realistic intervals to simulate the presence of a real duck.

### 7.3 Key Perfromance Indecators
Software Performance: 
- All autonomous behaviors (navigation, low-battery fallback) must pass simulated and real-world test cases with ≥ 90% consistency.
- Control system must maintain a response time below 200 ms in manual mode.

Hardware Performance:
- Motors maintain operation within ±10% of the expected RPM under normal conditions.
- Obstacle detection system has an accuracy of ≥ 95% within the 0.5–2 meter range.
- Motor temperature stays below X°C during prolonged use (value to be defined through testing).

Operational Success:
- The duck must maintain floating position and movement stability in at least 85% of tested water conditions (e.g., small waves, uneven pond surfaces).
- The robot must successfully complete an autonomous navigation, demonstrating at least 80% success rate in obstacle avoidance scenarios during test runs.

<a name="appendix"></a>
# Appendix 
### Appendix A: Work Breakdown Structure 
![Work](/doc/images/workbreakdown.png)
