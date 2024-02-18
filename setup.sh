#!/bin/bash

# Function to detect the operating system
detect_os() {
    case "$(uname -s)" in
        Darwin) echo "macos" ;;
        Linux) echo "linux" ;;
        CYGWIN*|MINGW32*|MSYS*|MINGW*) echo "windows" ;;
        *) echo "unknown" ;;
    esac
}

# Function to install dependencies
install_dependencies() {
    local os=$1
    case "$os" in
        linux)
            sudo apt update && sudo apt install -y git build-essential gcc g++ make libpng-dev
            ;;
        macos)
            brew install git gcc make libpng
            ;;
        windows)
            echo "Manual installation required for Git, Make, GCC (or MinGW), and libpng. Please ensure they are installed."
            read -p "Press [Enter] once installation is complete."
            ;;
        *)
            echo "Unsupported OS. Please manually install Git, Make, GCC, and libpng."
            exit 1
            ;;
    esac
}

# Function to configure N64 development environment
configure_n64_env() {
    read -p "Enter the directory for N64_INST (default: ~/n64): " N64_INST
    N64_INST=${N64_INST:-~/n64}
    export N64_INST
    echo "N64_INST is set to $N64_INST"
    
    # Clone libdragon
    git clone --branch unstable https://github.com/DragonMinded/libdragon.git "$N64_INST/libdragon-unstable"
    if [ $? -ne 0 ]; then
        echo "Failed to clone libdragon."
        exit 1
    fi

    # Build libdragon
    (cd "$N64_INST/libdragon-unstable/tools" && make)
    if [ $? -ne 0 ]; then
        echo "Failed to build libdragon."
        exit 1
    fi
}

# Function to download UNFLoader
download_unfloader() {
    local version="v2.11"
    local url="https://github.com/buu342/N64-UNFLoader/releases/download/$version/UNFLoader-$version.zip"
    curl -L "$url" -o UNFLoader.zip
    unzip UNFLoader.zip -d "$N64_INST"
    rm UNFLoader.zip
    if [ $? -ne 0 ]; then
        echo "Failed to download or unpack UNFLoader."
        exit 1
    fi
}

# Function to set environment variables permanently
set_environment() {
    local shell_profile
    if [ -f "$HOME/.bash_profile" ]; then
        shell_profile="$HOME/.bash_profile"
    elif [ -f "$HOME/.profile" ]; then
        shell_profile="$HOME/.profile"
    else
        shell_profile="$HOME/.bashrc"
    fi

    echo "export N64_INST=$N64_INST" >> "$shell_profile"
    echo "N64_INST environment variable set in $shell_profile"
}

# Main script execution
main() {
    local os=$(detect_os)
    echo "Detected OS: $os"
    install_dependencies "$os"
    configure_n64_env
    download_unfloader
    set_environment
    echo "Setup complete. Please restart your terminal or source your profile to apply changes."
}

# Execute the main function
main
