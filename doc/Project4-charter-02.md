




# Project charter

### Embedded application – Duck
##### Author: group 2 <br> Location: Fontys University, Tegelseweg 255, 5912 BG Venlo <br> Version:   <br>  Date: 




## **Abstract:**
This project aims to develop an amphibious robotic duck that mimics the appearance and behaviour of a real duck while freeing of the need for animal care. Designed for outdoor ponds, it offers a lifelike alternative for the presence of a duck without the responsibilities of keeping one. By combining embedded systems with autonomous movement the project aims to create a functional, self-sustaining robotic companion for outdoor settings in order to replace ducks.

**Acronyms**


|**Abbreviation**|**Meaning**|
| :- | :- |


<br>
<br>


**Version history**

|**Version**|**Date**|**Comment**|
| :-: | :-: | :-: |
|0\.1|....|First draft|


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
\- The purpose of a business case description is to provide an overview of the justification for
the project from a business perspective.
– ...need or opportunity, the expected benefits and outcomes.
– The business case description helps stakeholders understand why the project is being
undertaken, what problem or opportunity it aims to address,
– ...how it aligns with the organization's strategic objectives


So far there is no good duck robot on the market that can mimic real duck behaviour and replace the need for actual ducks on one's pond. The developed robot takes this opportunity to fill that market gap and has a big estimated revenue.
The duck robot is a big opportunity to learn about the world of embedded systems.
Our strategic objective is to pass the project 4 module and therefore the duck is a great robot that covers a lot of expected technologies.




# 3. Approach
The project will be conducted in a hybrid scrum way of working with a sprint length of 1 week. A Kanban board will be used to take track of all the use cases that have to be completed and a planning meeting will be used to plan the work for every sprint. Also daily stand up meetings will be used to keep every team member on track with the state of the project.
To achieve the projects objectives the project will be planned first by ordering and researching all the necessary components needed for the robot to function. On arrival of the components, the project team will use two project weeks with 20 hours of weekly working time to build actual initial hardware and at the end of the semester there will be additional 3 weeks of 40 hours of weekly working time to finish and complete the robot. Every other normal week a minimum of 5 hours will be spend working on the project.
### 3.1 In Scope 
The must have scope functionality of the duck robot includes:
- A working distance sensor that detects the shore
- An algorithm that turns the robot when it detects the shore and steers it into a different direction
- A driving system that lets the duck move straight with the help of a compass.
- A working speaker that plays different "Quack" sounds
- It needs to operate on its on for at least an hours
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
...to outline the approach and processes that will be employed to ensure that the
project's deliverables meet the required quality standards
– Quality Objectives (e.g. ISO XXXXX, CE certified)
– Quality Assurance (formal compliance checks with the standards)
– Quality Control (pair programming, code review)
– Roles and Responsibilities (quality representative, who is responsible in the end)



# 6. Prerequisite
to outline any specific requirements or conditions that must be met before the
project can proceed successfully
– Hardware Requirements
– Software Requirements
– Infrastructure Requirements
– Skills and Expertise
` `-> Can be used later for requirements engineering




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