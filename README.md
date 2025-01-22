
# Bitel POS Software for E-15 Transactions

This is a Point of Sale (POS) software built in C for deployment on Bitel IC-5100 devices. The software facilitates E-15 services mandated by the Sudanese government, allowing efficient processing of receipts, payments, and other government transactions.

## Features
- Optimized for Bitel IC-5100 hardware.
- Implements E-15 government services for Sudan.
- Supports Arabic and English interfaces.
- Real-time receipt generation, service updates, and transaction logging.

## Technical Details
- **Programming Language**: C.
- **Device Compatibility**: Bitel IC-5100.
- **Core Functionalities**:
  - Service updates.
  - Invoice issuance and cancellation.
  - Receipt printing.
  - Multi-language support.
- **Utilities Used**:
  - Serial communication with peripherals.
  - LCD and printer interfacing.
  - Secure transaction handling.

## Installation on Bitel IC-5100
1. **Prepare the Device**:
   - Ensure the Bitel IC-5100 is connected to a reliable power source.
   - Check that the device has sufficient memory for deployment.

2. **Upload Software**:
   - Use the manufacturer's deployment tool (Hyper Terminal or a similar utility) to transfer the compiled binary files to the device.
   - Connect the device via the serial or USB port, depending on your setup.

3. **Deploy Files**:
   - Upload the following key files:
     - Compiled binary (`.bin` or `.hex` file).
   - Set the correct memory allocation during the file transfer to avoid overwriting existing applications.

4. **Finalize Installation**:
   - Restart the device after the upload process.
   - Access the device menu to select and activate the newly installed software.

5. **Network Configuration**:
   - Set up network parameters for real-time transaction processing:
     - **APN**: Enter the Access Point Name provided by your telecom provider.
     - **IP Address**: Configure the server's IP address for E-15 service connectivity.
     - **Port Number**: Use the port assigned by the Sudanese E-15 service.

## Key Functionalities
- **Main Menu**:
  - Login to the system.
  - Access settings, including language and operational mode.
  - Perform bill payments or issue receipts.
- **Settings**:
  - Configure date, time, terminal ID, and server details.
  - Change passwords and reset to factory defaults.
- **Operational Modes**:
  - Online: Requires active network connectivity.
  - Offline: Allows limited functionality without a network.

## Notes
- The software includes debug options for troubleshooting. Enable these in development mode by defining `USER_DEBUG` in the code.
- Ensure secure storage of all configuration files to maintain transaction integrity.
