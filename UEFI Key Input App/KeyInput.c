#include <Uefi.h>
#include <Library/UefiLib.h>

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
)
{
  EFI_INPUT_KEY Key;
  Print(L"Press any key...\n");
  SystemTable->ConIn->ReadKeyStroke(SystemTable->ConIn, &Key);
  Print(L"Key pressed. ScanCode: %d\n", Key.ScanCode);
  return EFI_SUCCESS;
}
