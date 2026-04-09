#include <Uefi.h>
#include <Library/UefiLib.h>
#include <Library/UefiBootServicesTableLib.h>

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
)
{
  EFI_EVENT TimerEvent;
  UINTN Index;

  gBS->CreateEvent(EVT_TIMER, 0, NULL, NULL, &TimerEvent);
  gBS->SetTimer(TimerEvent, TimerRelative, 3 * 10000000);

  Print(L"Waiting for 3 seconds...\n");
  gBS->WaitForEvent(1, &TimerEvent, &Index);

  Print(L"Timer expired!\n");
  return EFI_SUCCESS;
}
