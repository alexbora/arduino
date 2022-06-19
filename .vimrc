call plug#begin('~/.vim/plugged')
Plug 'morhetz/gruvbox' 
Plug 'junegunn/goyo.vim'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'honza/vim-snippets'
"Plug 'neoclide/coc.nvim', { 'branch': 'master', 'do': 'yarn install --frozen-lockfile' }

""Plug 'tpope/vim-fugitive'


Plug 'drmikehenry/vim-headerguard'
Plug 'tibabit/vim-templates'
Plug 'tpope/vim-commentary'


""Plug 'neoclide/vim-easygit'
""Plug 'https://github.com/yegappan/taglist'
call plug#end()
set bg=dark


set encoding=utf-8

" TextEdit might fail if hidden is not set.
set hidden

" Some servers have issues with backup files, see #649.
set nobackup
set nowritebackup

" Give more space for displaying messages.
set cmdheight=2

" Having longer updatetime (default is 4000 ms = 4 s) leads to noticeable
" delays and poor user experience.
set updatetime=300

" Don't pass messages to |ins-completion-menu|.
set shortmess+=c

" Always show the signcolumn, otherwise it would shift the text each time
" diagnostics appear/become resolved.
if has("nvim-0.5.0") || has("patch-8.1.1564")
  " Recently vim can merge signcolumn and number column into one
  set signcolumn=number
else
  set signcolumn=yes
endif


" Add `:Format` command to format current buffer.
command! -nargs=0 Format :call CocAction('format')



"set statusline^=%{coc#status()}%{get(b:,'coc_current_function','')}


" let g:clang_format#style_options = {"BasedOnStyle":"Mozilla"}
" let g:clang_format#auto_format=1

function FormatBuffer()
   " if &modified && !empty(findfile('.clang-format', expand('%:p:h') . ';'))
     let cursor_pos = getpos('.')
     " :%!clang-format
     :%!clang-format --style=file
     call setpos('.', cursor_pos)
   " endif
 endfunction

" AICI E FORMATAREA

autocmd BufWritePre *.h,*.hpp,*.c,*.cpp,*.vert,*.frag :Format
" autocmd BufWritePre *.h,*.hpp,*.c,*.cpp,*.vert,*.frag :call FormatBuffer()

" let g:clang_complete_macros = 1
inoremap <silent><expr> <cr> pumvisible() ? coc#_select_confirm()
                              \: "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"

set backspace=indent,eol,start

nnoremap <leader>g :Goyo<CR>

autocmd BufWinLeave *.* mkview
autocmd BufWinEnter *.* silent loadview


set makeprg=gcc-11\ -o\ %<\ %\ -w\ -Ofast\ -falign-loops=32\ -march=native\ -mrdrnd\ -lm\ -pthread\ -lwebsockets\ -lxlsxwriter\ -ljson-c\ -lssl\ -lcrypto\ -std=c11\ -lgsl\ -lgslcblas\ -fsanitize=alignment\ -fsanitize=bounds\ -fsanitize=float-divide-by-zero\ -fsanitize=null\ -fsanitize=pointer-overflow\ -fsanitize=unreachable\ -fsanitize=undefined\ -fstrict-aliasing\ -fsanitize=signed-integer-overflow\ -fsanitize=float-cast-overflow\ -fsanitize=return\ -fsanitize=vptr\ -fsanitize=enum\ -fsanitize=address\ -fno-omit-frame-pointer\ -static-libstdc++\ -static-libgcc\ -static-libasan\ -lrt\ -ggdb3

" set makeprg=gcc-11\ -ggdb3\ -std=gnu2x\ -o\ %<\ %\ -pthread\ -lwebsockets\ -lssl\ -lcrypto\ -lcurl\ -ljson-c\ -mavx512f\ -w\ -fstrict-aliasing\ -Ofast\ -luv\ -lev\ -g\ -pg\ -mfma\ -march=native\ -mlzcnt\ -ftree-vectorize\ -fno-stack-protector
			" -llinasm\ -
			""\ -fno-omit-frame-pointer\ -mfma
			
			""\ -ltcmalloc\ -lprofiler
			""\ -fprofile-arcs
" set makeprg=gcc-11\ -o\ %:p:r\ %:p\ -std=c99\ -lpthread\ -Wstrict-aliasing\ -Wrestrict\ -Wzero-length-bounds
"set makeprg=clang\ -ggdb\ -std=gnu99\ -o\ %<\ %\ -lpthread\ -lwebsockets\ -lssl\ -lcrypto\ -lcurl\ -ljson-c\ -mavx\ -Weverything\ -fstrict-aliasing\ -O3\ -lev\ -luv

set t_Co=256
colo gruvbox

"  if has("autocmd")
 "     augroup templates_
  "      autocmd BufNewFile *.cpp 0r ~/temp.cpp
   " 	autocmd BufNewFile *.c 0r ~/temp.c
    "  augroup END
   " endif

"let g:C_SourceCodeExtensions  = 'h cc cp cxx cpp CPP c++ C i ii'

 
"  if has("autocmd")
 "     augroup templates_
  "  	autocmd BufNewFile *.h call HeaderguardAdd()
      "augroup END
 "   endif

"nnoremap <space>e :CocCommand explorer<CR>
"let g:easygit_enable_command = 1
"autocmd BufNewFile,BufRead /tmp/mutt* set noautoindent filetype=mail wm=0 tw=78 nonumber digraph nolist
"autocmd BufNewFile,BufRead ~/tmp/mutt* set noautoindent filetype=mail wm=0 tw=78 nonumber digraph nolist


set undodir=~/tmp/undo
set undofile " Maintain undo history between sessions
" set hidden
" set noswapfile
"autocmd bufenter  ~/tmp/* :set noswapfile
"set backupdir=/var/tmp,/tmp
"set directory=/var/tmp,/tmp

set nomodeline
set lazyredraw

set textwidth=200
nmap <silent> gd <Plug>(coc-definition)
"nmap <silent> gy <Plug>(coc-implementation)
"nmap <silent> gr <Plug>(coc-references)
set tags=./tags;/

"----------------------------------------------------------""

"nnoremap <silent> K :call <SID>show_documentation()<CR>

"function! s:show_documentation()
 "" if (index(['vim','help'], &filetype) >= 0)
  ""  execute 'h '.expand('<cword>')
  "else
   "" call CocAction('doHover')
  "endif
"endfunction

"autocmd CursorHold * silent call CocActionAsync('highlight')

"nmap <leader>rn <Plug>(coc-rename)


"command! -nargs=? Fold :call     CocAction('fold', <f-args>)


"nnoremap <silent> <space>a  :<C-u>CocList diagnostics<cr>

nnoremap // :Commentary<cr>

" :vnoremap <Leader>a "ay
" :vnoremap <Leader>A "Ay
" :nnoremap <Leader>a "ap
