# Bill-Payment Challenge 

## How to build
- JavaScript
  - `npm install`
  - `npm test billpay.js`
- Python
  - `python3 billpay.py`

## Constraints
- For this project we will be using only the JavaScript standard library
- Your interviewer is your pair! Be sure to ask questions and talk through your thoughts.
- Test driven development is encouraged!


## Project Description
You need to design and write a program that calculates a bill’s payment date based on a given due date. A bill’s payment date may differ from its due date based on specific rules for each bill type. Below are requirements that outline the rules to calculate the payment date for each bill type.

## Requirements
- The payment date for a mortgage bill falls on the closest business day ON or AFTER the due date.
- The payment date for a water bill falls on the closest business day ON or BEFORE the due date.
- The payment date for an electric bill falls on the closest business day ON, BEFORE, or AFTER the due date
- Holidays are considered non-business days. (Use the HolidayService to determine when a normal weekday is a holiday.)

