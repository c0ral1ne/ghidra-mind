import streamlit as st
from reconstruct import reconstruct
from utils import run_ghidra

st.set_page_config(
    page_title="Ghidra Mind",
    layout="wide",
    initial_sidebar_state="expanded"
)

if 'code' not in st.session_state:
    st.session_state.code = None
if 'reconstructed_code' not in st.session_state:
    st.session_state.reconstructed_code = None

st.title("🧠 Ghidra Mind ")
st.markdown("""
A reverse engineering tool that decompiles and reconstructs binaries into **readable C source code**.  
Built on **Ghidra** and enhanced by **GPT-5**, it transforms binaries into human-intuitive code — all within a simple, interactive interface.
""")

# --- File Upload Section ---
st.sidebar.header("Upload Binary")
uploaded_file = st.sidebar.file_uploader(
    "Choose a binary file",
    help="Upload the compiled binary you want to decompile"
)

# --- Decompile and reconstruct options ---
st.sidebar.header("Reconstruction Options")
opt_structs = st.sidebar.checkbox("Infer Structs", value=True)
opt_var_names = st.sidebar.checkbox("Regenerate Symbolic Variable Names", value=True)
opt_comments = st.sidebar.checkbox("Include AI-Generated Comments", value=False)
opt_style = st.sidebar.selectbox(
    "Code Style",
    ["Verbose", "Compact", "Annotated"],
    index=0
)

col1, col2 = st.sidebar.columns(2)
with col1:
    decompile_btn = st.button("Decompile", use_container_width=True, disabled=uploaded_file is None)
with col2:
    reconstruct_btn = st.button("Reconstruct", use_container_width=True, disabled=uploaded_file is None or st.session_state.code is None)


# --- Placeholder: Generation Statistics Table ---
# st.markdown("### 📊 Generation Statistics")
# stats_data = {
#     "Metric": ["Tokens Used", "Latency (s)", "LLM Model", "Success Rate"],
#     "Value": ["–", "–", "–", "–"]
# }
# stats_df = pd.DataFrame(stats_data)
# st.table(stats_df)

# --- Code Output Section ---
if uploaded_file and decompile_btn:
    st.session_state.code = run_ghidra(uploaded_file)
    st.session_state.reconstructed_code = None

if st.session_state.code and reconstruct_btn:
    st.session_state.reconstructed_code = reconstruct(st.session_state.code)

tab1, tab2 = st.tabs(["🧱 Original Decompiled", "🧠 Reconstructed (LLM)"])
with tab1:
    st.code(st.session_state.code, language="c")
with tab2:
    st.code(st.session_state.reconstructed_code, language="c")

