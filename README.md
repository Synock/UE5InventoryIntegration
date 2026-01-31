# UE5InventoryIntegration

This is a demonstration project showing how to integrate the **UE5Inventory** plugin into a barebone Unreal Engine 5 third-person project.

## Project Overview

The InventoryMinimum project serves as a **practical integration example** for developers who want to add the UE5Inventory plugin to their own third-person projects. This project starts from Unreal Engine's basic third-person template and demonstrates the minimal steps needed to successfully integrate and configure the inventory system.

### What You'll Learn
- How to add the UE5Inventory plugin as a Git submodule
- How to configure plugin dependencies in your project
- Basic setup and initialization of the inventory system
- Integration with a standard third-person character

## Requirements

- Unreal Engine 5.x
- Visual Studio 2022 (for C++ development)
- Git LFS (recommended for large binary assets)

## Getting Started

1. Clone the repository with submodules:
   ```bash
   git clone --recurse-submodules git@github.com:Synock/UE5InventoryIntegration.git
   ```
   
   Or if you already cloned it, initialize the submodules:
   ```bash
   git submodule update --init --recursive
   ```

2. The UE5Inventory plugin submodule is on the `DurabilityAndFixes` branch by default

3. Right-click on `InventoryMinimum.uproject` and select "Generate Visual Studio project files"

4. Open `InventoryMinimum.sln` in Visual Studio

5. Build the solution (Build > Build Solution)

6. Launch the project by running the .uproject file or pressing F5 in Visual Studio

## Plugins

### UE5Inventory
The project includes the **UE5Inventory** plugin as a Git submodule, which provides the core inventory system functionality. The submodule is configured to use the `DurabilityAndFixes` branch, which includes:
- Item durability system
- Equipment durability tracking
- Various bug fixes and improvements

The plugin is located at `Plugins/UE5Inventory/` and is automatically managed through Git submodules.

## Project Structure

- **Plugins/UE5Inventory/** - The inventory plugin as a Git submodule
- **Source/InventoryMinimum/** - C++ source code with plugin integration examples
- **Content/** - Blueprint assets and third-person level
- **Config/** - Project configuration files

## Next Steps

After setting up this project, you can:
- Explore the plugin's features in the third-person level
- Review the integration code to understand how the plugin is initialized
- Use this project as a template for adding the inventory system to your own projects
- Refer to the UE5Inventory plugin documentation for advanced features

## License

See LICENSE file for details.
