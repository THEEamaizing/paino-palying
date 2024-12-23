#include <iostream>
#include <qrencode.h>

int main() {
    const char* data = "https://www.example.com";
    QRcode* qrcode = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8);

    if (!qrcode) {
        std::cerr << "Error generating QR code" << std::endl;
        return 1;
    }

    unsigned char* qrcodeData = qrcode->data;
    int qrcodeSize = qrcode->width;

    // Create a PPM image file
    std::ofstream file("qrcode.ppm");
    file << "P6\n" << qrcodeSize << " " << qrcodeSize << "\n255\n";

    for (int y = 0; y < qrcodeSize; y++) {
        for (int x = 0; x < qrcodeSize; x++) {
            unsigned char pixel = qrcodeData[y * qrcodeSize + x];
            file.write(reinterpret_cast<char*>(&pixel), 3); // Write RGB pixel data
        }
    }

    file.close();
    QRcode_free(qrcode);

    std::cout << "QR code generated as qrcode.ppm" << std::endl;

    return 0;
}