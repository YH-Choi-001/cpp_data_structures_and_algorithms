for file in *.cpp; do
    if [ -f "$file" ]; then
        output_name="${file/.cpp/.out}"
        g++ "$file" -o "$output_name"
        "./${output_name}"
        rm "$output_name"
    fi
done