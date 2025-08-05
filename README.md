## Hotel

Let's imagine you have a hotel log book in a following format

```csv
Name,Check-in time,Check-out time
John,2025755662,3243571437
Phill,2067831537,3502815654
```

`Check-in` and `Check-out` are always less or equals to MAX(UINT32)

### Task 1

You will need to find a time period at which there was the largest number of guests in the hotel.
Print the start of that time period and list of guests

### Task 2

Add easily extendable support for different input methods