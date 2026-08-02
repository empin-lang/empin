#!/bin/sh
TOKEN_FILE="$HOME/mytoken"
PROJECT_DIR="$HOME/empin"

cd "$PROJECT_DIR" || exit 1

ASKPASS_SCRIPT=$(mktemp)
cat > "$ASKPASS_SCRIPT" << 'ASKEOF'

echo $(cat $HOME/mytoken)
ASKEOF

chmod +x "$ASKPASS_SCRIPT"

export GIT_ASKPASS="$ASKPASS_SCRIPT"
export GIT_TERMINAL_PROMPT=0

git push -u origin main

rm -f "$ASKPASS_SCRIPT"
unset GIT_ASKPASS GIT_TERMINAL_PROMPT
