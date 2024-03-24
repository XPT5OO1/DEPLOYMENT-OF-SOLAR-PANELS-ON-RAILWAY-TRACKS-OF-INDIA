#include <iostream>
#include <iomanip>
#include <string>

// Function to manually set data (replace this with your actual data)
void setManualData(std::string states[], double railwayTrackLength[], double averageSunlightHours[], int size) {
    // Replace the following lines with your actual data
    states[0] = "Andhra Pradesh";
    railwayTrackLength[0] = 6075;
    averageSunlightHours[0] = 2025.75;

    states[1] = "Arunachal Pradesh";
    railwayTrackLength[1] = 12;
    averageSunlightHours[1] = 1354.15;

    states[2] = "Assam";
    railwayTrackLength[2] = 2702;
    averageSunlightHours[2] = 1733.75;

    states[3] = "Bihar";
    railwayTrackLength[3] = 5418;
    averageSunlightHours[3] = 1861.5;

    states[4] = "Chhattisgarh";
    railwayTrackLength[4] = 2183;
    averageSunlightHours[4] = 1930.85;

    states[5] = "Delhi";
    railwayTrackLength[5] = 346;
    averageSunlightHours[5] = 1843.25;

    states[6] = "Goa";
    railwayTrackLength[6] = 69;
    averageSunlightHours[6] = 1978.3;

    states[7] = "Gujarat";
    railwayTrackLength[7] = 6357;
    averageSunlightHours[7] = 2033.05;

    states[8] = "Haryana";
    railwayTrackLength[8] = 2652;
    averageSunlightHours[8] = 1876.1;

    states[9] = "Himachal Pradesh";
    railwayTrackLength[9] = 317;
    averageSunlightHours[9] = 1733.75;

    states[10] = "Jammu and Kashmir";
    railwayTrackLength[10] = 366;
    averageSunlightHours[10] = 1810.4;

    states[11] = "Jharkhand";
    railwayTrackLength[11] = 4383;
    averageSunlightHours[11] = 1887.05;

    states[12] = "Karnataka";
    railwayTrackLength[12] = 4837;
    averageSunlightHours[12] = 1963.7;

    states[13] = "Kerala";
    railwayTrackLength[13] = 1745;
    averageSunlightHours[13] = 1664.4;

    states[14] = "Madhya Pradesh";
    railwayTrackLength[14] = 8216;
    averageSunlightHours[14] = 1923.55;

    states[15] = "Maharashtra";
    railwayTrackLength[15] = 8712;
    averageSunlightHours[15] = 2095.1;

    states[16] = "Manipur";
    railwayTrackLength[16] = 13;
    averageSunlightHours[16] = 1733.75;

    states[17] = "Meghalaya";
    railwayTrackLength[17] = 9;
    averageSunlightHours[17] = 1668.05;

    states[18] = "Mizoram";
    railwayTrackLength[18] = 2;
    averageSunlightHours[18] = 1835.95;

    states[19] = "Nagaland";
    railwayTrackLength[19] = 11;
    averageSunlightHours[19] = 1686.3;

    states[20] = "Odisha";
    railwayTrackLength[20] = 4443;
    averageSunlightHours[20] = 1810.4;

    states[21] = "Punjab";
    railwayTrackLength[21] = 2768;
    averageSunlightHours[21] = 1814.05;

    states[22] = "Rajasthan";
    railwayTrackLength[22] = 8174;
    averageSunlightHours[22] = 2047.65;

    states[23] = "Tamil Nadu";
    railwayTrackLength[23] = 5492;
    averageSunlightHours[23] = 1887.05;

    states[24] = "Telangana";
    railwayTrackLength[24] = 2596;
    averageSunlightHours[24] = 1868.8;

    states[25] = "Tripura";
    railwayTrackLength[25] = 265;
    averageSunlightHours[25] = 1784.85;

    states[26] = "Uttarakhand";
    railwayTrackLength[26] = 451;
    averageSunlightHours[26] = 1762.95;

    states[27] = "Uttar Pradesh";
    railwayTrackLength[27] = 12957;
    averageSunlightHours[27] = 1949.1;

    states[28] = "West Bengal";
    railwayTrackLength[28] = 7624;
    averageSunlightHours[28] = 1868.8;

    states[29] = "Chandigarh";
    railwayTrackLength[29] = 18;
    averageSunlightHours[29] = 1817.7;

    states[30] = "Puducherry";
    railwayTrackLength[30] = 22;
    averageSunlightHours[30] = 2040.35;
}

int main() {
    const int size = 31;  

    // Manually set data
    std::string states[size];
    double railwayTrackLength[size];
    double averageSunlightHours[size];

    setManualData(states, railwayTrackLength, averageSunlightHours, size);

    // Initialising variables
    double sum_energy = 0;
    double sum_energy_cost = 0;
    double sum_panel_cost = 0;

    // Defining Constants
    const double solarPanelEfficiency = 0.22;
    const double electricEnergyCost = 3.69;  // (in Rupees per kWh)
    const double performanceRatio = 0.75;
    const double per_sq_meter_cost = 6782.945; // (in Rupees)

    // Calculating net energy for each state
    double energyGeneratedCost[size] = {0.0};
    double energyGeneratedPerYear[size] = {0.0};
    double solarPanelCost[size] = {0.0};

    for (int i = 0; i < size; ++i) {
        // Calculating Energy generated in a year in kilowatt-hours (kWh) for each state
        energyGeneratedPerYear[i] = performanceRatio * averageSunlightHours[i] * railwayTrackLength[i] * solarPanelEfficiency / 1000; // (in Giga Watts)

        // Calculating Energy generated cost in Rupees per kWh for each state
        energyGeneratedCost[i] = 1000 * 1000 * energyGeneratedPerYear[i] * electricEnergyCost / 1e7;

        // Calculating Total Solar Panel cost for each State
        solarPanelCost[i] = railwayTrackLength[i] * 1000 * per_sq_meter_cost / 1e7;
    }

    // Displaying the results
    std::cout << std::setw(15) << "STATE" << std::setw(25) << "ENERGY GENERATED" << std::setw(30) << "GENERATED ENERGY COST" << std::setw(30) << "SOLAR PANEL COST" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << std::setw(15) << states[i] << std::setw(25) << std::fixed << std::setprecision(2) << energyGeneratedPerYear[i]
                  << std::setw(30) << std::fixed << std::setprecision(5) << energyGeneratedCost[i]
                  << std::setw(30) << std::fixed << std::setprecision(5) << solarPanelCost[i] << std::endl;

        sum_energy += energyGeneratedPerYear[i];
        sum_energy_cost += energyGeneratedCost[i];
        sum_panel_cost += solarPanelCost[i];
    }

    // Displaying the total results
    std::cout << "Total Energy Generated: " << std::fixed << std::setprecision(2) << sum_energy << " GW" << std::endl;
    std::cout << "Total Energy Generated Price: " << std::fixed << std::setprecision(2) << sum_energy_cost << " Crores" << std::endl;
    std::cout << "Total Solar Panel Cost for India: " << std::fixed << std::setprecision(2) << sum_panel_cost << " Crores" << std::endl;

    return 0;
}
