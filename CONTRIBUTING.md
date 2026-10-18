# Contribution Guidelines

Vcov is a community‑driven effort. Currently, almost all of the development for the Vcov Project is done by Wissem alone in his spare time, so your contributions are invaluable!

## Issues

The easiest way to contribute is by reporting issues with `vcov.exe` tool.

## Pull Requests

We are happy to accept pull requests for fixes, features
and updates,  In order to avoid wasting your time, we highly encourage opening an issue to discuss whether the PR you're thinking about making will be acceptable.

### Naming Style Conventions

- Folder naming:  PascalCase. Example: `Core`, `ThirdParty`

- File naming:  PascalCase. The filename should match the class name if the file contains its declaration or implementation.  Example: `CoverageAnalyzer.cpp`, `CoverageAnalyzer.h`

- Function names:  camelCase. Example: `computeCoverageRate`

- Classes and types:  PascalCase.  Example: `CoverageRateComputer`

- Macros:  uppercase with underscores.  Example: `MAX_BUFFER_SIZE`

- Constants: lowercase.  Example: `pi = 3.14159`

- Member variables: camelCase with a suffix (`_`) or prefix (`m_`). Avoid inconsistent styles.  

```cpp
class CoverageAnalyzer {
private:
    int coverageRate_;   // Preferred suffix style
    int m_coverageRate;  // Alternative prefix style
    int CoverageRate;    // Avoid: PascalCase for members
    int coverage_rate;   // Avoid: snake_case for members
};
