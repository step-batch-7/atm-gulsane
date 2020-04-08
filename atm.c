#include <stdio.h>

#include "./atm.h"

void print_notes(unsigned int notes)
{
  unsigned short denomination[] = DENOMINATIONS;
  unsigned int count = 0;
  for (int i = 0; i < 8; i++)
  {
    count = (notes << (4 * i)) >> 28;
    if (count)
    {
      printf("%2d %s of Rs. %d\n", count, count > 1 ? "notes" : "note ", denomination[i]);
    }
  }
}

unsigned int get_money(unsigned short int amount)
{
  unsigned int notes_count = 0x00000000;
  if (amount > 31999)
  {
    return notes_count;
  }
  unsigned short denomination[] = DENOMINATIONS;
  for (int index = 0; index < 8; index++)
  {
    notes_count = notes_count << 4;
    notes_count += amount / denomination[index];
    amount %= denomination[index];
  }
  return notes_count;
}