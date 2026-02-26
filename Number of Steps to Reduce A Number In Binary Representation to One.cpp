int steps = 0;
bool hasCarry = false;

for (int i = s.size() - 1; i > 0; --i) {
    char currentBit = s[i];

    if (hasCarry) {
        if (currentBit == '0') {
            currentBit = '1';
            hasCarry = false;
        } else {
            currentBit = '0';
        }
    }

    if (currentBit == '1') {
        ++steps;
        hasCarry = true;
    }

    ++steps;
}

if (hasCarry) {
    ++steps;
}

return steps;
