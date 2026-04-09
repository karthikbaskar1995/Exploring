#include <Uefi.h>
#include <Library/UefiLib.h>

EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
)
{
  Print(L"Firmware Vendor : %s\n", SystemTable->FirmwareVendor);
  Print(L"UEFI Version    : %d.%d\n",
        SystemTable->Hdr.Revision >> 16,
        SystemTable->Hdr.Revision & 0xFFFF);
  return EFI_SUCCESS;
}
``
